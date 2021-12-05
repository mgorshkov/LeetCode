//
//  validate-ip-address.cpp
//  
//
//  Created by Mikhail Gorshkov on 05.12.2021.
//

//Given a string queryIP, return "IPv4" if IP is a valid IPv4 address, "IPv6" if IP is a valid IPv6 address or "Neither" if IP is not a correct IP of any type.
//
//A valid IPv4 address is an IP in the form "x1.x2.x3.x4" where 0 <= xi <= 255 and xi cannot contain leading zeros. For example, "192.168.1.1" and "192.168.1.0" are valid IPv4 addresses but "192.168.01.1", while "192.168.1.00" and "192.168@1.1" are invalid IPv4 addresses.
//
//A valid IPv6 address is an IP in the form "x1:x2:x3:x4:x5:x6:x7:x8" where:
//
//1 <= xi.length <= 4
//xi is a hexadecimal string which may contain digits, lower-case English letter ('a' to 'f') and upper-case English letters ('A' to 'F').
//Leading zeros are allowed in xi.
//For example, "2001:0db8:85a3:0000:0000:8a2e:0370:7334" and "2001:db8:85a3:0:0:8A2E:0370:7334" are valid IPv6 addresses, while "2001:0db8:85a3::8A2E:037j:7334" and "02001:0db8:85a3:0000:0000:8a2e:0370:7334" are invalid IPv6 addresses.
//

class Solution {
public:
    bool hexDigitOk(char c) {
        return c >= 'a' && c <= 'f' || c >= 'A' && c <= 'F' || c >= '0' && c <= '9';
    }
    
    bool decimalDigitOk(char c) {
        return c >= '0' && c <= '9';
    }
    
    string checkIPv6IPv4(const string& queryIP) {
        for (int i = 0; i < queryIP.size(); ++i) {
            if (queryIP[i] == ':')
                return checkIPv6(queryIP);
            else if (queryIP[i] == '.')
                return checkIPv4(queryIP);
        }
        return "Neither";
    }
    
    string checkIPv6(const string& queryIP) {
        int offset = 0;
        // supposedly it's IPv6 address
        for (int group = 0; group < 8; ++group) {
            if (group > 0 && queryIP[offset++] != ':') {
                return "Neither";
            }
            for (int digit = 0; digit < 4; ++digit) {
                char c = queryIP[offset];
                if (digit > 0 && (c == ':' || c == '\0')) {
                    break;
                }
                ++offset;
                if (!hexDigitOk(c)) {
                    return "Neither";
                }
            }
        }
        if (offset != queryIP.size()) {
            return "Neither";
        }
        return "IPv6";
    }
    
    string checkIPv4(const string& queryIP) {
        int offset = 0;
        for (int octet = 0; octet < 4; ++octet) {
            if (octet > 0 && queryIP[offset++] != '.') {
                return "Neither";
            }
            int number = 0;
            bool zero = false;
            for (int pos = 0; pos < 3; ++pos) {
                char c = queryIP[offset];
                if (pos > 0 && (c == '.' || c == '\0')) {
                    break;
                }
                ++offset;
                if (!decimalDigitOk(c)) {
                    return "Neither";
                }
                int num = c - '0';
                if (num == 0) {
                    zero = true;
                }
                if (zero && pos == 0 && queryIP[offset] != '.' && queryIP[offset] != '\0') {
                    return "Neither";
                }
                number = number * 10 + num;
            }
            if (number > 255) {
                return "Neither";
            }
        }
        if (offset != queryIP.size()) {
            return "Neither";
        }
        return "IPv4";
    }
    
    string validIPAddress(string queryIP) {
        return checkIPv6IPv4(queryIP);
    }
};
