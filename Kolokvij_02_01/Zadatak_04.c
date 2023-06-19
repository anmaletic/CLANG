


typedef struct datoteka
{
    char naziv[64535+1];
    int velicina;
} datoteka;



datoteka* FindBig(datoteka* datoteke, int l)
{
    int najId = 0;
    int najVelicina = 0;

    for (int i = 0; i < l; i++)
    {
        if(datoteke[i].naziv[0] != '.')
        {
            if (datoteke[i].velicina > najVelicina)
            {
                najVelicina = datoteke[i].velicina;
                najId = i;
            }
        }
    }
    return &datoteke[najId];
}


int main(void)
{
    datoteka datoteke[5] = { {"jfdspojfopsdj pjpfjsdp jfopsjdop", 12}, {". pjpfjsdp jfopsjdop", 10002}, {"jfdspojfopsdj jfopsjdop", 38}, {"pjpfjsdp dsajfopsjdop", 123}, {"pjpfjsdpdassda dsajfopsjdop", 93} }; 

    datoteka *dat = FindBig(datoteke, 5);

    int sdat = (*datoteke).velicina;
}