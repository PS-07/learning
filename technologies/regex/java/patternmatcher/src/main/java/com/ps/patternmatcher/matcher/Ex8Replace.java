package com.ps.patternmatcher.matcher;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Ex8Replace {
    public static void main(String[] args) {
        String text = "John writes about this, and John Doe writes about that, and John Wayne writes about everything.";
        String regex = "((John) (.+?)) ";

        Pattern pattern = Pattern.compile(regex);
        Matcher matcher = pattern.matcher(text);

        // Matcher.replaceAll(String replacement) replaces all occurances of matched text with replacement
        String replaceAll = matcher.replaceAll("Joe Blocks ");
        System.out.println("replaceAll   = " + replaceAll);

        // Matcher.replaceFirst(String replacement) replaces the first occurances of matched text with replacement
        String replaceFirst = matcher.replaceFirst("Joe Blocks ");
        System.out.println("replaceFirst = " + replaceFirst);
    }
}
