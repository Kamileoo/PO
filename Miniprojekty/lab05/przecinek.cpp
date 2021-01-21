#include <iostream>
#include <vector>
 
using namespace std;
 
vector<int> operator * (vector<int> v, const int& obj){
	v.push_back (obj);
	return v;
}
 
vector<int> operator , (vector<int> v, const int& obj){
	v.push_back (obj);
	return v;
}
 
vector<int> przecinek = (vector<int>() , 1, 2, 3);
vector<int> gwiazdka = (vector<int>() * 1 * 2 * 3);
 
 
int main(){
    przecinek = przecinek , 4 , 5 , 6;
    gwiazdka = gwiazdka * 4 * 5 * 6;
 
	for(auto it : przecinek){
		cout<< it <<" ";
	}
	cout<<"\n";
	for(auto it : gwiazdka){
		cout<< it <<" ";
	}
	cout<<"\n";
 
	return 0;
}