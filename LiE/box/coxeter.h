

entry simp_inprod(entry* x,entry * y,simpgrp* g);
entry Inprod(entry* x,entry * y);
entry simp_norm(entry* alpha, simpgrp* g);
entry Norm(entry* alpha);
entry Cart_inprod(entry* x, entry* alpha);
matrix* Reflection(entry* alpha);

lie_Index simp_make_dominant(entry* lambda, simpgrp* g);
lie_Index make_dominant(entry* lambda);
vector* Dominant(vector* lambda);
lie_Index Length(vector* w);
vector* Wwordv(entry* lambda, lie_Index l);
vector* Wwordm(matrix* m);
vector* Canonical(vector* w);
matrix* Canonicals(matrix* m);
matrix* Filter_dom_m(matrix* m);
poly* Filter_dom(poly* p);

vector* L_red(vector* L,entry* w,lie_Index lw);
vector* Reduce(vector* v);
vector* LR_red(vector* L,entry* w,lie_Index lw,vector* R);

boolean Bh_leq(vector* v,vector* w);
matrix* Bh_desc(entry* w, lie_Index l);
matrix* Bh_desc_rel(entry* w, lie_Index l, entry* lwb);

void make_q(void);
void clear_q(void);
poly* Rpoly(vector* x, vector* y);
poly* KLpoly(vector* x, vector* y);


