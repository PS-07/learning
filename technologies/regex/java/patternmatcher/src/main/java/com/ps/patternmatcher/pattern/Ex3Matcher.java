package com.ps.patternmatcher.pattern;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Ex3Matcher {
    public static void main(String[] args) {
        String text = "Is it okay? This is the text to be searched. THIS IS IT!";
        String regex = ".*is.*";

        // obtain Matcher instance from Pattern instance which can 
        // be used to find matches of the pattern in texts
        Pattern pattern = Pattern.compile(regex, Pattern.CASE_INSENSITIVE);
        Matcher matcher = pattern.matcher(text);
        boolean matchFound = matcher.matches();
        
        System.out.println("match found: " + matchFound);
    }
    
}
