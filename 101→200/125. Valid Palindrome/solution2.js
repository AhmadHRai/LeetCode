/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function(s) {
    let str = s.replace(/[^a-z0-9]/gi, '').toLowerCase();
    let rev = str.split("").reverse().join("");
    return (str == rev) ? true : false;
};

/* 
s.replace(/[^a-z0-9]/gi, ''): This operation uses the replace() method along with a regular expression to remove all non-alphanumeric characters from the string s.

/[^a-z0-9]/gi: This is the regular expression used. Here, [^a-z0-9] specifies a character set that matches any character that is not a lowercase letter (a-z) or a digit (0-9). The caret (^) inside the square brackets negates the set, so it matches any character not in the set. The g flag after the regular expression is for "global", which means it will replace all matches in the string, not just the first one. The i flag is for "ignore case", which makes the match case-insensitive, so it will match both lowercase and uppercase letters.

'': This is the replacement value, which is an empty string. When a match is found, it is replaced with nothing, effectively removing it from the string.

*/
