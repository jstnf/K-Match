package dev.justinf.kmatch;

import com.wrapper.spotify.model_objects.specification.Playlist;
import com.wrapper.spotify.model_objects.specification.Track;
import dev.justinf.kmatch.spotify.SpotifyAPI;
import dev.justinf.kmatch.sql.KMDatabase;

import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class KMSpotifyGet {

    private final List<String> ignoredWords;
    private final SpotifyAPI api;
    private KMDatabase database;

    public KMSpotifyGet() {
        ignoredWords = new ArrayList<>();
        api = new SpotifyAPI(this);
    }

    public void start() {
        System.out.println("K-Match \"Spotify-Get\" Utility");

        Scanner input = new Scanner(System.in);
        System.out.print("Enter database address: ");
        String dbAddress = input.nextLine();
        System.out.print("Enter database port: ");
        String dbPort = input.nextLine();
        System.out.print("Enter database username: ");
        String dbUser = input.nextLine();
        System.out.print("Enter database password: ");
        String dbPass = input.nextLine();
        System.out.println("Enter Spotify playlist ids, separated by commas.");
        System.out.print(" > ");
        api.addPlaylistIds(input.nextLine().split(","));
        System.out.println("Enter ignored keywords, separated by commas.");
        System.out.print(" > ");
        ignoredWords.addAll(Arrays.asList(input.nextLine().split(",")));

        database = new KMDatabase(this, dbAddress, dbPort, dbUser, dbPass);

        System.out.println("\nYour information:");
        System.out.println("Database connection info:");
        System.out.println(" - " + database.getUser() + "@" + database.getAddress() + ":" + database.getPort());
        System.out.println("Spotify Playlist IDs:");
        for (String id : api.getPlaylistIds()) {
            System.out.println(" - " + id);
        }
        System.out.println("Ignored keywords (case-insensitive):");
        for (String word : ignoredWords) {
            System.out.println(" - " + word);
        }

        try {
            System.out.println("\nBeginning process in 5 seconds...");
            Thread.sleep(5000);
            connectAndAuthenticate();
        } catch (Exception ignored) { }
    }

    private void connectAndAuthenticate() {
        System.out.println("Attempting connection to SQL database...");
        if (database.init()) {
            System.out.println("Successfully connected to SQL database!");
        } else {
            System.out.println("Failed to connect to database. Aborting process!");
            return;
        }

        System.out.println("Creating K-Match SQL database...");
        boolean created;
        try {
            created = database.createDatabase();
        } catch (SQLException e) {
            e.printStackTrace();
            System.out.println("There was an error creating/validating the K-Match database. Aborting process!");
            return;
        }

        if (!created) {
            boolean choiceMade = false;
            Scanner input = new Scanner(System.in);
            while (!choiceMade) {
                System.out.println("It seems a database already exists for K-Match.");
                System.out.println("Abort the database update process? (y/n)");
                System.out.println("Choosing 'n' will wipe and update the database, 'y' will terminate the program.");

                String choice = input.nextLine();
                switch (choice.toLowerCase()) {
                    case "y":
                        System.out.println("Aborting database update process.");
                        System.out.println("Goodbye! :)");
                        return;
                    case "n":
                        choiceMade = true;
                        System.out.println("Preparing database for update from Spotify...");
                        try {
                            database.validateTables();
                        } catch (SQLException e) {
                            e.printStackTrace();
                            System.out.println("There was an error preparing the database for updating. Aborting process!");
                            return;
                        }
                        System.out.println("Database successfully cleared and prepared for update!");
                        break;
                    default:
                        System.out.println("Invalid choice! Please specify 'y' or 'n'.");
                        break;
                }
            }
        }

        System.out.println("Successfully verified the K-Match database.");
        System.out.println("Requesting Spotify authentication token... Redirecting you to browser!");
        if (!api.requestAuthCode()) {
            System.out.println("There was an error with the authentication request process. Please try again later.");
        }
    }

    public void authFailed() {
        System.out.println("Unable to get Spotify authentication token! Please try again later.");
    }

    public void authSuccess(String code) {
        boolean tokenObtained = api.getAuthToken(code);
        if (!tokenObtained) {
            System.out.println("There was an error getting the authentication token. Please try again later!");
            return;
        }

        System.out.println("Successfully obtained Spotify authentication token.");
        System.out.println("Proceeding to scrape entries and write to database...");

        System.out.println("\nStaging playlists:");
        for (String id : api.getPlaylistIds()) {
            System.out.println("Requesting playlist information for playlist id " + id + "...");
            Playlist playlist = api.stagePlaylist(id);
            if (playlist == null) {
                System.out.println("Error staging playlist with id " + id + "!");
            } else {
                System.out.println("Success!");
                System.out.println(" - " + playlist.getId());
                System.out.println(" - \"" + playlist.getName() + "\"");
                System.out.println(" - " + playlist.getTracks().getTotal() + " tracks (expected)");
            }
        }

        System.out.println("\nPlaylists staged. Beginning track scrape process...");
        int processed = 0;
        for (Map.Entry<String, Playlist> pair : api.getStagedPlaylists().entrySet()) {
            processed++;
            System.out.println("Scraping " + pair.getValue().getName() + " playlist!");
            List<Track> tracks = api.getEntirePlaylistTracks(pair.getKey());
            if (tracks == null) {
                System.out.println("Error obtaining tracks! Please try again.");
            } else {
                System.out.println("SCRAPE SUMMARY FOR PLAYLIST \"" + pair.getValue().getName() + "\":");
                System.out.println("Obtained " + tracks.size() + " out of " + pair.getValue().getTracks().getTotal() + " expected tracks from the playlist!");

                System.out.println("Beginning database upload of " + tracks.size() + " tracks...");
                try {
                    database.uploadTracks(tracks.toArray(new Track[0]));
                } catch (Exception e) {
                    e.printStackTrace();
                    System.out.println("Error uploading tracks. Continuing to next playlist...");
                }
            }

            if (processed < api.getStagedPlaylists().size()) {
                System.out.println("Waiting 5 seconds before scraping next playlist...\n");
                try {
                    Thread.sleep(5000);
                } catch (Exception ignored) { }
            }
        }
    }

    /* getset */
    public KMDatabase getDatabase() {
        return database;
    }

    public List<String> getIgnoredWords() {
        return ignoredWords;
    }
}