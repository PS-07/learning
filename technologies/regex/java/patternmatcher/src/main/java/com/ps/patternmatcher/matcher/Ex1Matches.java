package com.ps.patternmatcher.matcher;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Ex1Matches {
    public static void main(String[] args) {
        String text = "This is the text to be searched for occurrences of the HTTP:// pattern.";
        String regex = ".*http://.*";

        // Matcher.matches() returns true if a match is found
        // it cannot be used to search for multiple occurances of regex in a text
        Pattern pattern = Pattern.compile(regex, Pattern.CASE_INSENSITIVE);
        Matcher matcher = pattern.matcher(text);
        boolean matchFound = matcher.matches();
        
        System.out.println("match found: " + matchFound);
    }
}
