package com.ps.patternmatcher.matcher;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Ex3Find {
    public static void main(String[] args) {
        String text =  "This is the text which is to be searched for occurrences of the word 'IS'.";
        String regex = "is";

        Pattern pattern = Pattern.compile(regex, Pattern.CASE_INSENSITIVE);
        Matcher matcher = pattern.matcher(text);

        // Matcher.find() searches for multiple occurances and returns the first, 
        // and then for each subsequent call to find() it will move to the next match
        // Matcher.start() gives the start index of the found match
        // Matcher.end() gives the end index + 1 of the found match
        int count = 0;
        while(matcher.find()) {
            count++;
            System.out.println("found: " + count + " : " + matcher.start() + " - " + matcher.end());
        }
    }
}
