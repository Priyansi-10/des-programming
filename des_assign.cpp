#include <bits/stdc++.h>

using namespace std;

#if defined(unix) || defined(__unix__) || defined(__unix)
#define PAUSE "read -p 'Press Enter to continue...' var"
#define CLR "clear"
#endif

/// @brief converts hexadecimal numbers to binary numbers
/// @param const string& str
/// @return binary string 
string hex_binary(const string& str)
{
    unorderedMap<char, string> hex_bin_map;

    hex_bin_map['0'] = "0000";
    hex_bin_map['1'] = "0001";
    hex_bin_map['2'] = "0010";
    hex_bin_map['3'] = "0011";
    hex_bin_map['4'] = "0100";
    hex_bin_map['5'] = "0101";
    hex_bin_map['6'] = "0110";
    hex_bin_map['7'] = "0111";
    hex_bin_map['8'] = "1000";
    hex_bin_map['9'] = "1001";
    hex_bin_map['A'] = "1010";
    hex_bin_map['B'] = "1011";
    hex_bin_map['C'] = "1100";
    hex_bin_map['D'] = "1101";
    hex_bin_map['E'] = "1110";
    hex_bin_map['F'] = "1111";

    string binary;

    for (char i : str)
    {
        binary = binary + hex_bin_map[i];
    }

    return binary;
}

/// @brief converts binary numbers to hexadecimal numbers
/// @param const string& str 
/// @return hex string
string binary_hex(const string& str)
{
    unorderedMap<char, string> bin_hex_map;

    bin_hex_map["0000"] = "0";
    bin_hex_map["0001"] = "1";
    bin_hex_map["0010"] = "2";
    bin_hex_map["0011"] = "3";
    bin_hex_map["0100"] = "4";
    bin_hex_map["0101"] = "5";
    bin_hex_map["0110"] = "6";
    bin_hex_map["0111"] = "7";
    bin_hex_map["1000"] = "8";
    bin_hex_map["1001"] = "9";
    bin_hex_map["1010"] = "A";
    bin_hex_map["1011"] = "B";
    bin_hex_map["1100"] = "C";
    bin_hex_map["1101"] = "D";
    bin_hex_map["1110"] = "E";
    bin_hex_map["1111"] = "F";

    string hex;

    for (int i = 0; i < str.length(); i+=4)
    {
        string chr;
        ch = ch + str[i];
        ch = ch + str[i+1];
        ch = ch + str[i+2];
        ch = ch + str[i+3];
        hex = hex + bin_hex_map[ch];
    }

    return hex;
}

/// @brief converts ascii to binary string
/// @param const string& str
/// @return binStr string
string ascii_binary(const string& str)
{
    string binStr;

    for (char ch : str)
    {
       binStr = binStr + std::bitset<8>(ch).to_string; 
    }
    
    return binStr;
}

/// @brief converts binary string to ascii
/// @param const string& str 
/// @return asciiStr string
string binary_ascii(const string& str)
{
   string asciiStr;

   std::stringstream s_stream(str);

   while (s_stream.good())
   {
    std::bitset<8> bits;
    s_stream >> bits;
    char ch = char(bits.to_ulong());
    asciiStr = asciiStr + ch;
   }

   return asciiStr;  
}

/// @brief permutes the string
/// @param string st, int* a, int n
/// @return permutated string p
string permutation(string st, int* a, int n)
{
    string p;

    int i = 0;
    while (i < n)
    {
        p = p + st[a[i]-1];
        i++;
    }

    return p;
}

/// @brief takes the given string and left shift it
/// @param string st, int shift 
/// @return string st
string shiftLeft(string st, int shift)
{
    string s;
    for (int i = 0; i < shift; i++)
    {
        for (int j = 1; j < 28; j++)
        {
            s = s + st[j];

        }
        
        s = s + st[0];
        st = s;
        s = "";
    }
    return st;
}

/// @brief 
/// @param 
/// @return
string xor_s(string a, string b)
{
    string c;

    int i = 0;
    while (i < a.size())
    {
        if (a[i]==b[i])
        {
            c = c + "0";
        }
        else
        {
            c = c + "1";
        }
        i++;
    }
    return c;
}

/// @brief code for encryption
/// @param string p, vector<string> rka, vector<string> rk
/// @return encrypted string c
string encryption(string p, vector<string> rka, vector<string> rk) 
{
    int initialPermutation[64] = 
    {58, 50, 42, 34, 26, 18, 10, 2, 
    60, 52, 44, 36, 28, 20, 12, 4, 
    62, 54, 46, 38, 30, 22, 14, 6, 
    64, 56, 48, 40, 32, 24, 16, 8, 
    57, 49, 41, 33, 25, 17, 9, 1,
    59, 51, 43, 35, 27, 19, 11, 3,
    61, 53, 45, 37, 29, 21, 13, 5,
    63, 55, 47, 39, 31, 23, 15, 7};

    p = permutation(pt, initialPermutation, 64);
    cout << "initial permutation = " << binary_hex(p) << endl;

    string l = p.substr(0, 32);
    string r = p.substr(32, 32);
    cout << "L0 = " << binary_hex(l) << endl;
    cout << "R0 = " << binary_hex(r) << endl;

    int expansionPermutation[48] = 
    {32, 1, 2, 3, 4, 5, 
    4, 5, 6, 7, 8, 9, 
    8, 9, 10, 11, 12, 13,
    12, 13, 14, 15, 16, 17,
    16, 17, 18, 19, 20, 21,
    20, 21, 22, 23, 24, 25,
    24, 25, 26, 27, 28, 29,
    28, 29, 30, 31, 32, 1};

    int sBox[8][4][16] = 
    {{14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7,
    0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,
    4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0,
    15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13},

    {15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10,
    3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,
    0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15,
    13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9},

    {10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8,
    13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,
    13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7,
    1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12},

    {7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,
    13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
    10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4,
    3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14},
    
    {2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9,
    14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6,
    4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14,
    11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3}, 
    
    {12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11,
    10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8,
    9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6,
    4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13},
    
    {4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,
    13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,
    1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2,
    6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12},
    
    {13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7,
    1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2,
    7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8,
    2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11}};

    int permutationFunction[32] = 
    {16, 7, 20, 21, 29, 12, 28, 17,
    1, 15, 23, 26, 5, 18, 31, 10,
    2, 8, 24, 14, 32, 27, 3, 9,
    19, 13, 30, 6, 22, 11, 4, 25};
    
    cout << endl;
    for (int i = 0; i < 16; i++)
    {
        string r_expand = permutation(r, expansionPermutation, 48);

        string x = xor_s(rka[i], r_expand);

        string op;
        for (int i = 0; i < 8; i++)
        {
            int row = 2 * int(x[i * 6]-'0') + int(x[i * 6 + 5] - '0');
            int col = 8 * int(x[i * 6 + 1] - '0') + 4 * int(x[i * 6 + 2] - '0') + 2 * int(x[i * 6 + 3] - '0') + int(x[i * 6 + 4] - '0');
            int val = sBox[i][row][col];
            op = op + char(val / 8 + '0');
            val = val % 8;
            op = op + char(val / 4 + '0');
            val = val % 4;
            op = op + char(val / 2 + '0');
            val = val % 2;
            op = op + char(val + '0');
        }

        op = permutation(op, permutationFunction, 32);

        x = xor_s(op, l);

        left = x;
        
        if (i != 15)
        {
            swap(l, r);
        }
        
        cout << "R" << i + 1 << " " << binary_hex(l) << " " << binary_hex(r) << " " << rk[i] << endl;
    }

    string add = l + r;

    int inverseInitiaPermutation[64] =
    {40, 8, 48, 16, 56, 24, 64, 32,
    39, 7, 47, 15, 55, 23, 63, 31,
    38, 6, 46, 14, 54, 22, 62, 30,
    37, 5, 45, 13, 53, 21, 61, 29,
    36, 4, 44, 12, 52, 20, 60, 28,
    35, 3, 43, 11, 51, 19, 59, 27,
    34, 2, 42, 10, 50, 18, 58, 26,
    33, 1, 41, 9, 49, 17, 57, 25
    };

    string c = permutation(add, inverseInitiaPermutation, 64);

    return c;
}

/// @brief generates new key by given key
/// @param string key, vector<string> &rka,  vector<string> &rk
void generate_key(string key,  vector<string> &rka,  vector<string> &rk){
    key = hex_binary(key);

    int keypar[56] = 
    {57, 49, 41, 33, 25, 17, 9,
    1, 58, 50, 42, 34, 26, 18,
    10, 2, 59, 51, 43, 35, 27,
    19, 11, 3, 60, 52, 44, 36,
    63, 55, 47, 39, 31, 23, 15,
    7, 62, 54, 46, 38, 30, 22,
    14, 6, 61, 53, 45, 37, 29,
    21, 13, 5, 28, 20, 12, 4};

    key = permutation(key, keypar, 56);

    int shiftTable[16] = 
    {1, 1, 2, 2,
    2, 2, 2, 2,
    1, 2, 2, 2,
    2, 2, 2, 1};

    int keyComp[48] = 
    {14, 17, 11, 24, 1, 5,
    3, 28, 15, 6, 21, 10,
    23, 19, 12, 4, 26, 8,
    16, 7, 27, 20, 13, 2,
    41, 52, 31, 37, 47, 55,
    30, 40, 51, 45, 33, 48,
    44, 49, 39, 56, 34, 53,
    46, 42, 50, 36, 29, 32};

    string l = key.substr(0, 28);
    string r = key.substr(28, 28);


    for (int i : shiftTable)
    {
        l = shiftLeft(l, i);
        r = shiftLeft(r, i);

        string add = l + r;

        string R_Key = permute(add, keyComp, 48);

        rka.push_back(R_Key);
        rk.push_back(binary_hex(R_Key));
    }

}

int main()
{
    char userInput;

    do
    {
        string plainText, key;
        string cipher, text;
        string binaryPlainText, hexPlainText, hexKey;
        vector<string> rka;
        vector<string> rk;

        char ch;
        cout << endl << endl << endl;
        system(PAUSE);
        system(CLR);

        cout << "DES Encryption/Decryption";
        cout << "------------------------------------------\n";
        cout << "\n 1. Encryption";
        cout << "\n 2. Decryption";
        cout << "\n\n x. Exit \n\n";
        cout << "Please enter your input: ";
        cin >> ch;
        cout << "----------------\n\n"

        switch (ch)
        {
        case '1':
            in.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter Plain Text (string of chars): ";
            getline(cin, plainText);

            cout << "Enter Key (HEX 16 Char): ";
            cin >> key;

            hexKey = key;
            generate_key(key, rka, rk);

            cout << "\nEncryption:\n\n";

            for (unsigned i = 0; i < plainText.length(); i = i + 8) {
                binaryPlainText = ascii_binary(plainText.substr(i, 8));
                cipher = cipher + encryption(binaryPlainText, rka, rk);
            }
            cipher = binary_hex(cipher);
            cout << "\n\tCipher Text (HEX): " << cipher << endl;
            cout << "\n----------------------\n " << endl;
            cout << "\n\tResult:" << endl;
            cout << "\n\tInput Plain Text: " << plainText << endl;
            cout << "\n\tKey (HEX): " << hexKey << endl;
            cout << "\n\tCipher Text (HEX): " << cipher << endl;
            break;

        case '2':
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout<<"Enter CipherText (HEX):";
            getline(cin, cipher);

            cout<<"Enter Key (HEX 16 Char): ";
            cin>>key;
            hexKey = key;
            
            generate_key(key, rka, rk);

            reverse(rka.begin(), rka.end());
            reverse(rk.begin(), rk.end());

            cout << "\nDecryption: \n\n";
            for (unsigned i = 0; i < cipher.length(); i = i + 16) {
                binaryPlainText = hex_binary(cipher.substr(i, 16));
                 text = text + encryption(binaryPlainText, rka, rk);
            }

            text = binary_ascii(text);
            cout << "\n\tPlain Text: " << text << endl;

            cout << "\n----------------------\n " << endl;
            cout << "\n\tResult:" << endl;

            cout << "\n\tKey (HEX): " << hexKey << endl;
            cout << "\n\tCipherText (HEX): " << cipher << endl;
            cout << "\n\tDecrypted Plain Text: " << text << endl;
            break;

        case 'x':
            cout << "You have successfully exited!";
            break;

        default:
            cout << "\n Invalid Input! Try Again.\n"; 
        }

        userInput = ch;

    } while (userInput ! = 'x');
    
    cout << "\n-->ENTER TO EXIT. \n";
    cin.get();
    cin.get();

    return 0;
}