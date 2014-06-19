

void initx (assem * asmb, unsigned int id);

void addx (assem * asmb, linklist * lst);



void freex (assem * asmb);

void freeallx (assem * asmb);

unsigned int numelementx (assem * asmb);

linklist *findbyidx (assem * asmb, unsigned int id);

int replacex (assem * asmb, linklist * lst, unsigned int id);

int deletex (assem * asmb, unsigned int id);

int insertx (assem * asmb, linklist * lst, unsigned int id);

