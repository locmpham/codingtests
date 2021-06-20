/*

    Given a string IP, return "IPv4" if IP is a valid IPv4 address, "IPv6" if IP is a valid IPv6 
    address or "Neither" if IP is not a correct IP of any type.

    A valid IPv4 address is an IP in the form "x1.x2.x3.x4" where 0 <= xi <= 255 and xi cannot contain 
    leading zeros.  For example, "192.168.1.1" and "192.168.1.0" are valid IPv4 addresses but "192.168.01.1", 
    while "192.168.1.00" and "192.168@1.1" are invalid IPv4 addresses.

    A valid IPv6 address is an IP in the form "x1:x2:x3:x4:x5:x6:x7:x8" where:

    1 <= xi.length <= 4

    xi is a hexadecimal string which may contain digits, lower-case English letter ('a' to 'f') and upper-case 
    English letters ('A' to 'F').

    Leading zeros are allowed in xi.

    For example, "2001:0db8:85a3:0000:0000:8a2e:0370:7334" and "2001:db8:85a3:0:0:8A2E:0370:7334" are valid 
    IPv6 addresses, while "2001:0db8:85a3::8A2E:037j:7334" and "02001:0db8:85a3:0000:0000:8a2e:0370:7334" are 
    invalid IPv6 addresses.
*/

#include <iostream>

using namespace std;

bool isdigit(char *cp) {
    if (*cp)
        return (*cp >= '0' && *cp <= '9');
    else
        return false;
}

bool isHexadecimal(char *cp) {
    if (*cp)
        return (isdigit(cp) || ((*cp >= 'a' && *cp <= 'f') || (*cp >= 'A' && *cp <= 'F')));
    else
        return false;
}

string validIPAddress(string IP) {
    int slen = IP.size();
    int validDigits = 0;
    int cnt;
    char *bp, *cp;
    
    if (slen == 0) {
        return "Neither";
    }
    
    // Check if we have correct # of separators 
    int dot = std::count(IP.begin(), IP.end(), '.');
    int colon = std::count(IP.begin(), IP.end(), ':');
    
 
    if (dot == 3 && colon == 0) {       // IPv4?
        
        if (slen > 15) {    // 4 digits of 3 chars max + 3 separators
            return "Neither";
        }
        
        cp = (char *)IP.c_str();
        
        while (*cp) {
            bp = cp;
            
            // check leading 0 - 0 followed by a digit
            if (*cp == '0' && isdigit(cp+1)) {
                // leading 0 not allowed in IPv4
                return "Neither";
            }
            
            // validate value 
            cnt = 0;
            while (*cp && isdigit(cp)) {
                cnt++;
                cp++;
            }
            if (cnt == 0) {
                // No digit found
                return "Neither";
            }

            if (*cp == '.' || *cp == 0) {
                // validate digit
                char tmp = *cp;
                *cp = 0;
                int val = atoi(bp);
                if (val < 0 || val > 255) {
                    // Invalid value
                    return "Neither";
                }
                validDigits++;
                if (tmp)
                    cp++;
            }
            else {
                // Bad format
                return "Neither";
            }
        }
        if (validDigits != 4) {
            // Invalid # of digits
            return "Neither";
        } else
            return "IPv4";
    }
    else if (dot == 0 && colon == 7) {  // IPv6?
        
        if (slen > 39) {  // 8 digits of 4 chars max + 7 separators
            return "Neither";
        }
        
        cp = (char *)IP.c_str();
    
        while (*cp) {
            bp = cp;
            cnt = 0;
            while (*cp && isHexadecimal(cp)) {
                cnt++;
                cp++;
            }
            if (cnt == 0 || cnt > 4) {
                // Invalid digit
                return "Neither";
            }
            if (*cp == ':' || *cp == 0) {
                validDigits++;
                if (*cp)
                    cp++;
            }
            else {
                // Invalid format
                return "Neither";
            }
        }
        if (validDigits != 8) {
            // Invalid # of digits
            return "Neither";
        } else
            return "IPv6";
    }
    return "Neither";
}


