package com.ps.patternmatcher.pattern;

import java.util.regex.Pattern;

public class Ex1Matches {
    public static void main(String[] args) {
        String text = "This is the text to be searched for occurrences of the pattern.";
        String regex = ".*is.*";

        // use Pattern.matches() when you just need to check a pattern against 
        // a text a single time with default settings of Pattern class
        boolean matchFound = Pattern.matches(regex, text);
        
        System.out.println("match found: " + matchFound);
    }
}
