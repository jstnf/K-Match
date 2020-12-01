package dev.justinf.kmatch.spotify;

import com.google.common.util.concurrent.FutureCallback;
import com.google.common.util.concurrent.Futures;
import com.google.common.util.concurrent.SettableFuture;
import com.google.gson.Gson;
import com.wrapper.spotify.Api;
import com.wrapper.spotify.methods.PlaylistRequest;
import com.wrapper.spotify.models.AuthorizationCodeCredentials;
import com.wrapper.spotify.models.Playlist;
import com.wrapper.spotify.models.PlaylistTrack;
import dev.justinf.kmatch.KMSpotifyGet;
import dev.justinf.kmatch.spotify.auth.KMAuthServer;

import java.awt.Desktop;
import java.net.URI;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class SpotifyAPI {

    public static final String CLIENT_ID = "9b961d67c9e3457ebcfd98128438d9f5";
    public static final String CLIENT_SECRET = "c04d24ae28fe4508abe0c7c587c9c142";
    public static final String REDIRECT_URI = "http://127.0.0.1:3000/auth";
    public static final String URL_STATE = "kmatchAuth";
    public static final List<String> SCOPES = Arrays.asList("user-read-private", "user-read-email");

    private static final String R_KPOP_USER_ID = "m0c30q17qpehqwup55yiqj0wg";

    private final KMSpotifyGet sg;
    private final KMAuthServer authServer;
    private final Set<String> playlistIds;
    private final Map<String, Playlist> stagedPlaylists;

    private Api api;

    public SpotifyAPI(KMSpotifyGet sg) {
        this.sg = sg;
        authServer = new KMAuthServer(sg);
        playlistIds = new HashSet<>();
        stagedPlaylists = new HashMap<>();
    }

    public void addPlaylistIds(String... ids) {
        playlistIds.addAll(Arrays.asList(ids));
    }

    public boolean requestAuthCode() {
        // Attempt to start the authentication callback server
        if (!authServer.start()) {
            return false;
        }

        api = Api.builder()
                .clientId(CLIENT_ID)
                .clientSecret(CLIENT_SECRET)
                .redirectURI(REDIRECT_URI)
                .build();

        String authorizeURL = api.createAuthorizeURL(SCOPES, URL_STATE);

        try {
            Desktop.getDesktop().browse(new URI(authorizeURL));
            return true;
        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }
    }

    public boolean getAuthToken(String code) {
        try {
            AuthorizationCodeCredentials creds = api.authorizationCodeGrant(code).build().get();
            /* Set the access token and refresh token so that they are used whenever needed */
            api.setAccessToken(creds.getAccessToken());
            api.setRefreshToken(creds.getRefreshToken());
            return true;
        } catch (Exception e) {
            e.printStackTrace();
            sg.authFailed();
            return false;
        }
    }

    public Playlist stagePlaylist(String playlistId) {
        PlaylistRequest request = api.getPlaylist(R_KPOP_USER_ID, playlistId).build();
        try {
            Playlist playlist = request.get();
            stagedPlaylists.put(playlistId, playlist);
            return playlist;
        } catch (Exception e) {
            e.printStackTrace();
            return null;
        }
    }

    public void scrape(Playlist playlist) {
        try {
            playlist.getTracks().getItems().stream().map(PlaylistTrack::getTrack).forEach(track -> sg.getDatabase().processTrack(track));
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    /* getset */
    public Set<String> getPlaylistIds() {
        return playlistIds;
    }
}