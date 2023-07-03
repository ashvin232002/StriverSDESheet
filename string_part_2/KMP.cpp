//writing the pseduo code

//take one array 
// LPS(N)   (Longest Proper Prfix which is also a Proper Suffix)
//Proper Prefix and Proper Suffix simply means that it does not include a whole string




/*
//This is The Pseduo code to fill the LPS table .
int i  = 1, int len  =  1

while(i<s.size()){
    if(s[i]==s[len]){
        len++;
        LPS[i] =  len ;
        i++;
    }else{
        if(len>0){
            len  =  LPS[len-1];
        }else{
            LPS[i]=0;
            i++;
        }
    }
}
*/


/*
DRY Run The Example

//count the number of times the pattern occurs inside the string s
s  =  "aabaacaabaad"
pattern =  "aab"

*/