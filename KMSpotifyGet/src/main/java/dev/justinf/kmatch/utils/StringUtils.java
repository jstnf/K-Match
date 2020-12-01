package dev.justinf.kmatch.utils;

public class StringUtils {

    public static String convertMillisToTime(int millis) {
        int seconds = millis / 1000 % 60;
        int minutes = millis / 60000;
        return minutes + ":" + (seconds < 10 ? "0" : "") + seconds;
    }
}