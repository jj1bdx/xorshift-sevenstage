/*
 * Code from
 * Figure 1,
 * François Panneton and Pierre L'ecuyer. 2005. 
 * On the xorshift random number generators. 
 * ACM Trans. Model. Comput. Simul. 15, 4 (October 2005), 346-361.
 * DOI=10.1145/1113316.11133
 */

#include <stdio.h>

static unsigned int x[8];	/* Generator's state.*/

/* Advances by one step and returns a number in [0,1).*/ 
unsigned int xorshift7 (void) {
    static int k = 0;
    unsigned int y, t;
    t = x[(k+7) & 0x7U]; t = t ^ (t<<13); y = t ^ (t<<9);
    t = x[(k+4) & 0x7U]; y ^= t ^ (t<<7);
    t = x[(k+3) & 0x7U]; y ^= t ^ (t>>3);
    t = x[(k+1) & 0x7U]; y ^= t ^ (t>>10);
    t = x [k] ;	t = t ^ (t>>7);	y ^= t ^ (t<<24);
    x[k] = y; k = (k+1) & 0x7U;
    return y;
}

int main(int argc, char *argv[]) {

    /* int i, j; */ /* documented but unused */
    union intout {
	unsigned int i;
	unsigned char c[4];
    } p;
   
    x[0] = 1804784013U;
    x[1] = 698059346U;
    x[2] = 3920535147U;
    x[3] = 708331212U;
    x[4] = 84338163U;
    x[5] = 2785678147U;
    x[6] = 1238376158U;
    x[7] = 1557298846U;

    while (1) {
	p.i = xorshift7();
	/* printf("%u ", xorshift7()); */
	putchar(p.c[0]);
	putchar(p.c[1]);
	putchar(p.c[2]);
	putchar(p.c[3]);
    }

}
