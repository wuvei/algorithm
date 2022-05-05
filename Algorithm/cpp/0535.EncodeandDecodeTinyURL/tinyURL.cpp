// Self-increase ID
class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        mp[id++] = longUrl;
        return base + to_string(id - 1);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[stoi(shortUrl.substr(19))];
    }
private:
    int id = 0;
    unordered_map<int, string> mp;
    string base = "http://tinyurl.com/";
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

class Solution {
    const string constLeading = "http://tinyurl.com/";
    const string code = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    unordered_map<size_t, string> tiny2origin;
    const int constLeadingLength = 19;
    hash<string> stringHash;
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        size_t lengthOfLongUrl = longUrl.size();
        size_t longUrlHashValue = stringHash(longUrl);
        tiny2origin[longUrlHashValue] = longUrl;
        string longUrlHashString;
        //longUrlHashValue to a base 62 string
        while (longUrlHashValue) {
            size_t currentCharOffset = longUrlHashValue % 62;
            // longUrlHashString += to_string(code[currentCharOffset]);
            longUrlHashString.append(1, code[currentCharOffset]);
            longUrlHashValue /= 62;
        }
        // add 2 char to the end。
        return constLeading + longUrlHashString.append(longUrl.substr(lengthOfLongUrl - 2,2));
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        size_t lengthOfShortUrl = shortUrl.size();

        size_t hashCodeOfShortUrl = 0;
        size_t availabelHashEnd = lengthOfShortUrl - 3;
        size_t currentCharIndex = constLeadingLength;

        size_t currentWeight = 1;
        
        while (currentCharIndex <= availabelHashEnd) {
            char currentChar = shortUrl[currentCharIndex];
            if (currentChar <= '9' && currentChar >= '0') {
                hashCodeOfShortUrl += currentWeight * (currentChar - '0');
            }
            else {
                if (currentChar <= 'z' && currentChar >= 'a')
                    hashCodeOfShortUrl += currentWeight * (currentChar - 'a' + 10);
                else if(currentChar <= 'Z' && currentChar >= 'A')
                    hashCodeOfShortUrl += currentWeight * (currentChar - 'A' + 36);
            }
            currentWeight *= 62;
            currentCharIndex++;
        }
        if (tiny2origin.count(hashCodeOfShortUrl)) {
            return tiny2origin[hashCodeOfShortUrl];
        }
        return "";
    }
};

// 作者：da-xiong-ge-ge
// 链接：https://leetcode-cn.com/problems/encode-and-decode-tinyurl/solution/qiu-zi-fu-chuan-hashzhi-zai-shi-yong-62jin-zhi-bia/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
    const string base = "http://tinyurl.com/";
    const string code = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    unordered_map<string, string> tiny2origin;
    const int BASE_LEN = 19, KEY_LEN = 6;
public:
    string generateFixLenRandKey() {
        string key;
        srand(time(0));
        for (int i = 0; i < KEY_LEN; i++) {
            key += code[random() % 62];
        }
        return key; 
    }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string randKey = generateFixLenRandKey();
        while (tiny2origin.find(randKey) != tiny2origin.end())
            randKey = generateFixLenRandKey();
        tiny2origin[randKey] = longUrl;
        return base + randKey;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string key = shortUrl.substr(BASE_LEN);
        if (tiny2origin.find(key) == tiny2origin.end())
            return "";
        return tiny2origin[key];
    }
};
