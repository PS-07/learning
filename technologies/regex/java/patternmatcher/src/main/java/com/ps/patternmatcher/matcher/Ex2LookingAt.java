package com.ps.patternmatcher.matcher;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Ex2LookingAt {
    public static void main(String[] args) {
        String text = "This is the text to be searched for occurrences of the HTTP:// pattern.";
        String regex = "is";

        // Matcher.lookingAt() returns true iff prefix of the text matches the pattern
        Pattern pattern = Pattern.compile(regex, Pattern.CASE_INSENSITIVE);
        Matcher matcher = pattern.matcher(text);
        boolean matchFound = matcher.lookingAt();
        
        System.out.println("match found at start of text: " + matchFound);
    }
}
