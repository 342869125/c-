
#include<iostream>
#include <string>
#include <sstream>
using namespace std;
	string a[1000][1000];
class Table{
	protected:
		int row;
		int column;
	public:
		Table(){
			row=1;
			column=1;
		}
		void show(){
			for(int i=0;i<row;i++){
				for(int j=0;j<column;j++){
					cout<<a[i][j]<<" ";
				}cout<<"\n";
			}
		cout<<"\n";	
		}
		void addRow(){
			row=row++;
		}
		void addColumn(){
			column=column++;
		}
		Table(int x,int y){
			row=x;
			column=y;
		}
		void set(int x,int y,int z){
			stringstream ss;
			string u;
			ss<<z;
			ss>>u;
			a[x][y]=u;
		}
		void set(int x,int y,string z){
			a[x][y]=z;
		}
		void delRow(int i){//ɾ����i�� 
			 for(int j=i;j<row-1;j++){
			 	string *p=a[j];
			 	*a[j]=*a[j+1];
				*a[j+1]=*p;
			 }
			 row--;
		} 
		void delColumn(int i){
			for(int j=i;j<column-1;j++){
				for(int k=0;k<row-1;k++){
					string p=a[j][k];
					a[j][k]=a[j][k+1];
					a[j][k+1]=p;
				}
			}
			column--;
		}
};
int main() {
  Table tb1;
  tb1.show();
  tb1.addRow();
  tb1.show();
  tb1.addColumn();
  tb1.show();
  Table tb2(5,5);
  tb2.show();
  tb2.set(1,1,30);
  tb2.set(3,3,"HelloWorld");
  tb2.show();
  tb2.delRow(1);
  tb2.show();
  tb2.delColumn(1);
  tb2.show();
  return 0;
}
