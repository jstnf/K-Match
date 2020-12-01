package dev.justinf.kmatch.spotify;

import com.wrapper.spotify.SpotifyApi;
import com.wrapper.spotify.SpotifyHttpManager;
import com.wrapper.spotify.model_objects.IPlaylistItem;
import com.wrapper.spotify.model_objects.credentials.AuthorizationCodeCredentials;
import com.wrapper.spotify.model_objects.specification.Paging;
import com.wrapper.spotify.model_objects.specification.Playlist;
import com.wrapper.spotify.model_objects.specification.PlaylistTrack;
import com.wrapper.spotify.model_objects.specification.Track;
import com.wrapper.spotify.requests.authorization.authorization_code.AuthorizationCodeUriRequest;
import com.wrapper.spotify.requests.data.playlists.GetPlaylistRequest;
import com.wrapper.spotify.requests.data.playlists.GetPlaylistsItemsRequest;
import com.wrapper.spotify.requests.data.tracks.GetSeveralTracksRequest;
import dev.justinf.kmatch.KMSpotifyGet;
import dev.justinf.kmatch.spotify.auth.KMAuthServer;

import java.awt.*;
import java.net.URI;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class SpotifyAPI {

    private static final String CLIENT_ID = "9b961d67c9e3457ebcfd98128438d9f5";
    private static final String CLIENT_SECRET = "c04d24ae28fe4508abe0c7c587c9c142";

    public static final URI REDIRECT_URI = SpotifyHttpManager.makeUri("http://127.0.0.1:3000/auth");
    public static final String URL_STATE = "kmatchAuth";
    public static final String SCOPES = "user-read-private,user-read-email";

    private final KMSpotifyGet sg;
    private final KMAuthServer authServer;
    private final Set<String> playlistIds;
    private final Map<String, Playlist> stagedPlaylists;

    private SpotifyApi api;

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

        api = new SpotifyApi.Builder()
                .setClientId(CLIENT_ID)
                .setClientSecret(CLIENT_SECRET)
                .setRedirectUri(REDIRECT_URI)
                .build();

        AuthorizationCodeUriRequest authorizeURL = api.authorizationCodeUri()
                .scope(SCOPES)
                .state(URL_STATE)
                .build();

        try {
            Desktop.getDesktop().browse(authorizeURL.execute());
            return true;
        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }
    }

    public boolean getAuthToken(String code) {
        try {
            AuthorizationCodeCredentials creds = api.authorizationCode(code).build().execute();
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
        GetPlaylistRequest request = api.getPlaylist(playlistId).build();
        try {
            Playlist playlist = request.execute();
            stagedPlaylists.put(playlistId, playlist);
            return playlist;
        } catch (Exception e) {
            e.printStackTrace();
            return null;
        }
    }

    public Paging<PlaylistTrack> getPlaylistTracks(String playlistId) {
        GetPlaylistsItemsRequest request = api.getPlaylistsItems(playlistId)
                .limit(50)
                .build();
        try {
            return request.execute();
        } catch (Exception e) {
            e.printStackTrace();
            return null;
        }
    }

    public Track[] getTracksDetailed(PlaylistTrack[] playlistTracks) {
        String[] array = new String[0];
        GetSeveralTracksRequest request = api.getSeveralTracks(Arrays.stream(playlistTracks)
                .map(PlaylistTrack::getTrack)
                .map(IPlaylistItem::getId)
                .toArray(String[]::new))
                .build();
        try {
            return request.execute();
        } catch (Exception e) {
            e.printStackTrace();
            return null;
        }
    }

    /* getset */
    public Set<String> getPlaylistIds() {
        return playlistIds;
    }
}