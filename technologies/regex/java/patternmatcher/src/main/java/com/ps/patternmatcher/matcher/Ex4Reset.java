package com.ps.patternmatcher.matcher;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Ex4Reset {
    public static void main(String[] args) {
        String text =  "This is the text which is to be searched for occurrences of the word 'IS'.";
        String regex = "is";

        Pattern pattern = Pattern.compile(regex, Pattern.CASE_INSENSITIVE);
        Matcher matcher = pattern.matcher(text);

        int count = 0;
        while(matcher.find()) {
            count++;
            System.out.println("found: " + count + " : " + matcher.start() + " - " + matcher.end());
        }
        
        // Matcher reset() method resets the matching state internally in the Matcher
        // matching will start from the beginning of the text again.
        matcher.reset();

        while(matcher.find()) {
            count++;
            System.out.println("found: " + count + " : " + matcher.start() + " - " + matcher.end());
        }
    }
}
