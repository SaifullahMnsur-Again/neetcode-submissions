class Solution {
    string add(char a, char b, char c) {
        int aa = a - '0';
        int bb = b - '0';
        int cc = c - '0';
        char cr = '0' + ((aa&bb) | (aa&cc) | (bb&cc));
        char sm = '0' + (aa^bb^cc);
        return string() + cr + sm;
    }
public:
    string addBinary(string a, string b) {
        string ans = "";
        char carry = '0';
        while(!a.empty() and !b.empty()) {
            string sum = add(a.back(), b.back(), carry);
            carry = sum[0];
            ans += sum[1];
            a.pop_back(); b.pop_back();
        }

        while(!a.empty()) {
            string sum = add(a.back(), '0', carry);
            carry = sum[0];
            ans += sum[1];
            a.pop_back();
        }


        while(!b.empty()) {
            string sum = add('0', b.back(), carry);
            carry = sum[0];
            ans += sum[1];
            b.pop_back();
        }
        
        if(carry == '1')
            ans += carry;
        
        reverse(ans.begin(), ans.end());

        return ans;
    }
};