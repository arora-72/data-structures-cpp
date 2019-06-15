// input - given string
// You need to remove all occurrences of character c that are present in string input.
// Change in the input itself. So no need to return or print anything.
using namespace std;
void removeAllOccurrencesOfChar(char str[], char c) {
    // Write your code here

    for(int i=0; str[i] != '\0';){
        //cout<<i<<endl;
        if(str[i] == c){
            int j=i;
            while(str[j] != '\0'){
                str[j] = str[j+1];
                j++;
            }
        }else{
            i++;
        }
    }
}
