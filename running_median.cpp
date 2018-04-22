/*Stupid code*/

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
        sort(a.begin(),a.begin()+a_i);//sort inserted elements
        //odd
        if(a_i%2 == 0){
            float num = a[a_i/2];
            cout<< fixed << setprecision(1) << num<<endl;
        }
        else{
            float num = ((a[a_i>>1]+a[(a_i>>1) +1 ]))*1.0/2;
            cout<< fixed << setprecision(1) << num<<endl;
        }
    }
    return 0;
}


