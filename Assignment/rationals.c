#include <stdio.h>
#include <math.h>

struct rational{
	int num;
	int den;
};

struct rational add_rational(struct rational a,struct rational b){
	struct rational c;
	c.num = (a.num*b.den) + (b.num*a.den);
	c.den = (a.den*b.den);
	return c;
}

struct rational sub_rational(struct rational a,struct rational b){
	struct rational c;
	c.num = (a.num*b.den) - (b.num*a.den);
	c.den = (a.den*b.den);
	return c;
}

struct rational mul_rational(struct rational a,struct rational b){
	struct rational c;
	c.num = a.num*b.num;
	c.den = a.den*b.den;
	return c;
}

struct rational div_rational(struct rational a,struct rational b){
	struct rational c;
	c.num = a.num*b.den;
	c.den = a.den*b.num;
	return c;
}

struct rational reduce_rational(struct rational a){
	int i;
  if (a.num > a.den){
	for (i=2;i<sqrt(a.den);i++){
       if (a.den%i == 0){
       	  if (a.num%i == 0){
       	  	while (a.den%i == 0 && a.num%i == 0){
       	  	a.den = a.den/i;
       	  	a.num = a.num/i;
       	     }
       	  }
       }
	}
	}
  else{
	for (i=2;i<sqrt(a.num);i++){
       if (a.num%i == 0){
       	  if (a.den%i == 0){
       	  	while(a.num%i == 0 && a.den%i == 0){
       	  	a.num = a.num/i;
       	  	a.den = a.den/i;
       	     }
       	  }
       }
	}
	}
	return a;
}

int main(){
	FILE *fp;
	struct rational data[100];
	int size,i;
	fp = fopen("answer.txt","r+");
	fscanf(fp,"%d",&size);
    for (i=0;i<size;i++){
    	fscanf(fp,"%d %d",&data[i].num,&data[i].den);
        }
    struct rational add = {0,1},average,s = {size,1};
    for (i=0;i<size;i++){
       add = add_rational(data[i],add);
       }
    add = reduce_rational(add);
    printf("The sum of the rationals is %d/%d\n",add.num,add.den);
    average = reduce_rational(div_rational(add,s));
    printf("The average of the rationals is %d/%d",average.num,average.den);
    fprintf(fp,"\nThe sum of the rationals is %d/%d",add.num,add.den);
    fprintf(fp,"\nThe average of the rationals is %d/%d",average.num,average.den);
}

