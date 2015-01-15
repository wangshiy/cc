/*
Problem:
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int l=digits.size();
        if(l==0){
            return digits;
        }
        if(l==1){
            if(digits[0]!=9){
                digits[0]++;
                return digits;
            }
            else{
                vector<int> v;
                v.push_back(1);
                v.push_back(0);
                return v;
            }
        }
        int flg=0;
        int temp=digits[l-1]+1;
        if(temp>9){
            digits[l-1]=0;
            flg=1;
        }
        else{
            digits[l-1]=temp;
            return digits;
        }
        for(int i=l-2;i>=0;i--){
            int temp=digits[i]+1;
            if(temp>9){
                digits[i]=0;
                flg=1;
            }
            else{
                digits[i]=temp;
                return digits;
            }
        }
        if(flg){
            //vector<int>::iterator it=;
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};