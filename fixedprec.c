#define N 4 // under point precision
#define M 2 // over point precision
#define NM (N+M)
#include <iostream>
typedef unsigned int ui;
typedef unsigned long long ull;
typedef unsigned __int128 ulll;
void m_init(ui* r,ull x){
	for(int i=0;i<N;i++)
		r[i]=0;
	for(int i=0;i<M;i++){
		r[N+i]=x;
		x>>=32;
	}
}
void m_plus(ui* r,ui* x,ui* y){
	ull k=0;
	for(int i=0;i<NM;i++){
		k+=(ull)x[i]+y[i];
		r[i]=k;
		k>>=32;
	}
}
ui m_minus(ui* r,ui* x,ui* y){
	long long k=0;
	for(int i=0;i<NM;i++){
		k+=(ull)x[i]-y[i];
		r[i]=k;
		k>>=32;
	}
	return k;
}
void m_times(ui* r,ui* x,ui* y){
	ulll tmp[2*NM]={0};
	for(int i=0;i<NM;i++)
		for(int j=0;j<NM;j++)
			tmp[i+j]+=(ull)x[i]*y[j];
	for(int i=0;i<(2*N+M);i++)
		tmp[i+1]+=tmp[i]>>32;
	for(int i=0;i<NM;i++)
		r[i]=tmp[i+N];
}
void m_div(ui* r,ui* x,ui* y){
	ui t[NM*2]={0};
	for(int i=0;i<NM;i++)
		r[i]=0;
	for(int i=0;i<NM;i++)
		t[i+N-M]=x[i]; // assert that doesnt exceed 1e64
	for(int i=NM*32-1;i>=0;i--){
		for(int j=NM*2-1;j>=0;j--){
			t[j]<<=1;
			if(j)
				t[j]|=t[j-1]>>31;
		}
		/*
		std::cout<<'T';
		for(int k=NM*2-1;k>=0;k--)
			std::cout<<t[k]<<' ';std::cout<<std::endl;
		std::cout<<'K';
		for(int k=NM-1;k>=0;k--)
			std::cout<<y[k]<<' ';std::cout<<std::endl;
		*/
		for(int j=NM*2-1;j>=0;j--){
			ui yy=j>=N&&j<NM+N?y[j-N]:0;
			if(t[j]>yy){
				//std::cout<<j<<' '<<i<<std::endl;
				
				r[i/32]|=1u<<(i%32);
				if(m_minus(t+N,t+N,y))
					for(int k=NM+N;!t[k]--;k++);
				break;
			}
			else if(t[j]<yy)
				break;
		}
	}
}
void m_log2(ui* r){
	
}

int main(){
	ui a[6]={0,0,0,0,134,0};
	ui b[6]={0,0,0,0,8,0};
	ui c[6],d[6];
	m_div(c,a,b);
	std::cout<<c[4];
}
