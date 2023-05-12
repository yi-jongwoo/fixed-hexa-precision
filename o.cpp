typedef unsigned int ui;
typedef unsigned long long ull;
#define o_plus(r0,r1,r2,r3,r4,r5,x0,x1,x2,x3,x4,x5,y0,y1,y2,y3,y4,y5) { \
	ull k=(ull)x0+y0; r0=k; k>>=32; \
	k+=(ull)x1+y1; r1=k; k>>=32; \
	k+=(ull)x2+y2; r2=k; k>>=32; \
	k+=(ull)x3+y3; r3=k; k>>=32; \
	k+=(ull)x4+y4; r4=k; k>>=32; \
	k+=(ull)x5+y5; r5=k; \
}
#define o_minus(r0,r1,r2,r3,r4,r5,x0,x1,x2,x3,x4,x5,y0,y1,y2,y3,y4,y5) { \
	ull k=(ull)x0-y0; r0=k; k>>=32; \
	k+=(ull)x1-y1; r1=k; k>>=32; \
	k+=(ull)x2-y2; r2=k; k>>=32; \
	k+=(ull)x3-y3; r3=k; k>>=32; \
	k+=(ull)x4-y4; r4=k; k>>=32; \
	k+=(ull)x5-y5; r5=k; \
}
#define o_times(r0,r1,r2,r3,r4,r5,x0,x1,x2,x3,x4,x5,y0,y1,y2,y3,y4,y5) { \
	ull t0=(ull)x0*y0; \
	ull t1=(t0>>32)+(ull)x0*y1; \
	ull t2=t1>>32; t1&=0xffffffff; t1+=(ull)x1*y0; \
	t2+=(t1>>32)+(ull)x0*y2; ull t3=t2>>32; t2&=0xffffffff; t2+=(ull)x1*y1; \
		t3+=t2>>32; t2&=0xffffffff; t2+=(ull)x2*y0; \
	t3+=(t2>>32)+(ull)x0*y3; ull t4=t3>>32; t3&=0xffffffff; t3+=(ull)x1*y2; \
		t4+=t3>>32; t3&=0xffffffff; t3+=(ull)x2*y1; \
		t4+=t3>>32; t3&=0xffffffff; t3+=(ull)x3*y0; \
	t4+=(t3>>32)+(ull)x0*y4; ull t5=t4>>32; t4&=0xffffffff; t4+=(ull)x1*y3; \
		t5+=t4>>32; t4&=0xffffffff; t4+=(ull)x2*y2; \
		t5+=t4>>32; t4&=0xffffffff; t4+=(ull)x3*y1; \
		t5+=t4>>32; t4&=0xffffffff; t4+=(ull)x4*y0; \
	t5+=(t4>>32)+(ull)x0*y5; ull t6=t5>>32; t5&=0xffffffff; t5+=(ull)x1*y4; \
		t6+=t5>>32; t5&=0xffffffff; t5+=(ull)x2*y3; \
		t6+=t5>>32; t5&=0xffffffff; t5+=(ull)x3*y2; \
		t6+=t5>>32; t5&=0xffffffff; t5+=(ull)x4*y1; \
		t6+=t5>>32; t5&=0xffffffff; t5+=(ull)x5*y0; \
	t6+=(t5>>32)+(ull)x1*y5; ull t7=t6>>32; t6&=0xffffffff; t6+=(ull)x2*y4; \
		t7+=t6>>32; t6&=0xffffffff; t6+=(ull)x3*y3; \
		t7+=t6>>32; t6&=0xffffffff; t6+=(ull)x4*y2; \
		t7+=t6>>32; t6&=0xffffffff; t6+=(ull)x5*y1; \
	t7+=(t6>>32)+(ull)x2*y5; ull t8=t7>>32; t7&=0xffffffff; t7+=(ull)x3*y4; \
		t8+=t7>>32; t7&=0xffffffff; t7+=(ull)x4*y3; \
		t8+=t7>>32; t7&=0xffffffff; t7+=(ull)x5*y2; \
	t8+=(t7>>32)+(ull)x3*y5; ui t9=t8>>32; t8&=0xffffffff; t8+=(ull)x4*y4; \
		t9+=t8>>32; t8&=0xffffffff; t8+=(ull)x5*y3; \
	t9+=(ull)x4*y5+(ull)x5*y4; \
	r0=t4; r1=t5; r2=t6; r3=t7; r4=t8; r5=t9; \
}
#define o_div(r0,r1,r2,r3,r4,r5,x0,x1,x2,x3,x4,x5,y0,y1,y2,y3,y4,y5) { 
	ui t0=0,t1=0,t2=x0,t3=x1,t4=x2,t5=x3,t6=x4,t7=x5,t8=0,t9=0,tA=0,tB=0;
	r0=0; r1=0; r2=0; r3=0; r4=0; r5=0;
	for (int i = 191; i >= 0; i--) {
		tB=tB<<1|tA>>31;
		tA=tA<<1|t9>>31;
		t9=t9<<1|t8>>31;
		t8=t8<<1|t7>>31;
		t7=t7<<1|t6>>31;
		t6=t6<<1|t5>>31;
		t5=t5<<1|t4>>31;
		t4=t4<<1|t3>>31;
		t3=t3<<1|t2>>31;
		t2=t2<<1|t1>>31;
		t1=t1<<1|t0>>31;
		t0<<=1;
		if( tB || tA ||
			t9>y5 || t9==y5&&(
			t8>y4 || t8==y4&&(
			t7>y3 || t7==y3&&(
			t6>y2 || t6==y2&&(
			t5>y1 || t5==y1&&(
			t4>=y0
		)))))){
			
		}
	}
}
