#define N 6 // under point precision
#define M 2 // over point precision
#define NM (N+M)

typedef unsigned int ui;
typedef unsigned long long ull;

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
void m_minus(ui* r,ui* x,ui* y){
	ull k=0;
	for(int i=0;i<NM;i++){
		k+=(ull)x[i]-y[i];
		r[i]=k;
		k>>=32;
	}
}
void m_times(ui* r,ui* x,ui* y){
	unsigned __int128 tmp[2*NM]={0};
	for(int i=0;i<NM;i++)
		for(int j=0;j<NM;j++)
			tmp[i+j]+=(ull)x[i]*y[j];
	for(int i=0;i<(2*N+M);i++)
		tmp[i+1]+=tmp[i]>>32;
	for(int i=0;i<NM;i++)
		r[i]=tmp[i+N];
}
void m_div(ui* r,ui* x,ui* y){
	ui arr[2*NM]={0};
	for(int i=M*32-1;i>=-N*32;i--){
		
	}
}
int main(){
	
}