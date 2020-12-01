package dev.justinf.kmatch.sql;

import com.mysql.cj.jdbc.Driver;
import com.wrapper.spotify.models.SimpleArtist;
import com.wrapper.spotify.models.Track;
import dev.justinf.kmatch.KMSpotifyGet;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.stream.Collectors;

public class KMDatabase {

    public static final String DATABASE_NAME = "kmatch";
    public static final String ARTIST_TABLE = "artists";
    public static final String ALBUM_TABLE = "albums";
    public static final String SONG_TABLE = "songs";

    private final KMSpotifyGet sg;

    private final String address;
    private final String port;
    private final String user;
    private final String pass;

    private Connection connection;

    public KMDatabase(KMSpotifyGet sg, String address, String port, String user, String pass) {
        this.sg = sg;
        this.address = address;
        this.port = port;
        this.user = user;
        this.pass = pass;
    }

    public boolean init() {
        try {
            DriverManager.registerDriver(new Driver());
            connection = DriverManager.getConnection("jdbc:mysql://" + address + ":" + port + "/mysql?autoReconnect=true", user, pass);
            connection.setAutoCommit(true);
            return true;
        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }
    }

    public boolean createDatabase() throws SQLException {
        PreparedStatement ps = connection.prepareStatement("SHOW DATABASES LIKE ?;");
        ps.setString(1, DATABASE_NAME);
        ResultSet rs = ps.executeQuery();
        if (rs.next()) {
            connection.setCatalog(DATABASE_NAME);
            return false;
        } else {
            ps = connection.prepareStatement("CREATE DATABASE " + DATABASE_NAME + ";");
            ps.executeUpdate();
            connection.setCatalog(DATABASE_NAME);
            validateTables();
            return true;
        }
    }

    public void validateTables() throws SQLException {
        createArtistTable();
        createAlbumTable();
        createSongTable();
    }

    public void processTrack(Track track) {
        System.out.println(track.getName());
        System.out.print(" - Artists: ");
        System.out.println(track.getArtists().stream().map(SimpleArtist::getName).collect(Collectors.joining(", ")));
        System.out.println(" - Album: " + track.getAlbum().getName());
        System.out.println(" - Duration: " + track.getDuration() + "ms");
        System.out.println(" - Popularity (0-100): " + track.getPopularity());
    }

    private void createArtistTable() throws SQLException {
        PreparedStatement ps = connection.prepareStatement("CREATE TABLE IF NOT EXISTS `" + ARTIST_TABLE + "` (" +
                "`id` VARCHAR(22) NOT NULL DEFAULT '', " +
                "`name` VARCHAR(100) NOT NULL DEFAULT '', " +
                "PRIMARY KEY (`id`));");
        ps.executeUpdate();

        // If table already exists, remove all entries
        ps = connection.prepareStatement("DELETE FROM `" + ARTIST_TABLE + "` WHERE 1 = 1;");
        ps.executeUpdate();
    }

    private void createAlbumTable() throws SQLException {
        PreparedStatement ps = connection.prepareStatement("CREATE TABLE IF NOT EXISTS `" + ALBUM_TABLE + "` (" +
                "`id` VARCHAR(22) NOT NULL DEFAULT '', " +
                "`artist` VARCHAR(22) NOT NULL DEFAULT '', " +
                "`name` VARCHAR(100) NOT NULL DEFAULT '', " +
                "PRIMARY KEY (`id`), " +
                "FOREIGN KEY (`artist`) REFERENCES " + ARTIST_TABLE + "(`id`));");
        ps.executeUpdate();

        // If table already exists, remove all entries
        ps = connection.prepareStatement("DELETE FROM `" + ALBUM_TABLE + "` WHERE 1 = 1;");
        ps.executeUpdate();
    }

    private void createSongTable() throws SQLException {
        PreparedStatement ps = connection.prepareStatement("CREATE TABLE IF NOT EXISTS `" + SONG_TABLE + "` (" +
                "`id` VARCHAR(22) NOT NULL DEFAULT '', " +
                "`name` VARCHAR(100) NOT NULL DEFAULT '', " +
                "`artist` VARCHAR(22) NOT NULL DEFAULT '', " +
                "`album` VARCHAR(22) NOT NULL DEFAULT '', " +
                "`duration` BIGINT NOT NULL DEFAULT 0, " +
                "`release` DATE NOT NULL, " +
                "`popularity` INT NOT NULL DEFAULT 0, " +
                "PRIMARY KEY (`id`), " +
                "FOREIGN KEY (`artist`) REFERENCES " + ARTIST_TABLE + " (`id`), " +
                "FOREIGN KEY (`album`) REFERENCES " + ALBUM_TABLE + " (`id`));");
        ps.executeUpdate();

        // If table already exists, remove all entries
        ps = connection.prepareStatement("DELETE FROM `" + SONG_TABLE + "` WHERE 1 = 1;");
        ps.executeUpdate();
    }

    /* getset */
    public String getAddress() {
        return address;
    }

    public String getPort() {
        return port;
    }

    public String getUser() {
        return user;
    }

    public String getPass() {
        return pass;
    }

    public Connection getConnection() {
        return connection;
    }
}