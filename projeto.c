#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

struct Question
{
    char question[100];
    char a[50];
    char b[50];
    char c[50];
    char d[50];
    char answer;
};

int quiz()
{
    printf("Bem vindo ao Jogo de perguntas!\n\n");

    struct Question questions[5];

    // Question 1
    sprintf(questions[0].question, "Qual foi o primeiro console lançado pela nintendo?");
    sprintf(questions[0].a, "Gameboy");
    sprintf(questions[0].b, "Snes");
    sprintf(questions[0].c, "NES");
    sprintf(questions[0].d, "Color TV-Game");
    questions[0].answer = 'd';

    // Question 2
    sprintf(questions[1].question, "Qual foi a geração de pokemon mais vendido em toda a franquia?");
    sprintf(questions[1].a, "Pokemon Red,Green,Blue");
    sprintf(questions[1].b, "Pokemon Fire Red e Leaf Green");
    sprintf(questions[1].c, "Pokemon Black e White");
    sprintf(questions[1].d, "Pokemon Diamong, Pearl e Platinum");
    questions[1].answer = 'a';

    // Question 3
    sprintf(questions[2].question, "Qual das empresas a Nintendo quase fez a parceria para o lançamento de um console?");
    sprintf(questions[2].a, "Apple");
    sprintf(questions[2].b, "Microsoft");
    sprintf(questions[2].c, "Sony");
    sprintf(questions[2].d, "Google");
    questions[2].answer = 'c';

    // Question 4
    sprintf(questions[3].question, "Qual é o console mais vendido no mundo?");
    sprintf(questions[3].a, "Playstation 2");
    sprintf(questions[3].b, "Nintendo DS");
    sprintf(questions[3].c, "Playstation 4");
    sprintf(questions[3].d, "Xbox 360");
    questions[3].answer = 'a';

    // Question 5
    sprintf(questions[4].question, "Qual o console da nintendo mais vendido no mundo?");
    sprintf(questions[4].a, "Nintendo DS");
    sprintf(questions[4].b, "GameBoy Advance");
    sprintf(questions[4].c, "Wii");
    sprintf(questions[4].d, "Nintendo Switch");
    questions[4].answer = 'a';

    // Ask the questions
    for (int i = 0; i < 5; i++)
    {
        printf("Pergunta %d: %s\n", i + 1, questions[i].question);
        printf("a) %s\n", questions[i].a);
        printf("b) %s\n", questions[i].b);
        printf("c) %s\n", questions[i].c);
        printf("d) %s\n", questions[i].d);
        char answer;
        printf("Coloque a sua resposta (a/b/c/d): ");
        scanf(" %c", &answer);

        if (answer == questions[i].answer)
        {
            printf("Correct!\n");
        }
        else if (!(answer == 'a' || answer == 'b' || answer == 'c' || answer == 'd'))
        {
            printf("Resposta inválida. Passando para próxima questão.\n");
        }
        else
        {
            char correctAn = questions[i].answer;
            printf("Incorreto. A resposta certa seria: %s \n", &correctAn);
        }

        printf("\n");
    }
    return 0;
}

struct Box
{
    char inside;
    int open;
};

struct Player
{
    char name[40];
    char tag;
};

int boxgame()
{
    srand(time(NULL));
    struct Box all_box[5];
    struct Player players[2];

    for (size_t i = 0; i < 5; i++)
    {
        all_box[i].inside = 'e';
        all_box[i].open = 0;
    }

    int snakeBox = rand() % 5;

    all_box[snakeBox].inside = 's';

    for (size_t n = 0; n < 1; n++)
    {
        int buttonBox = rand() % 5;
        if (all_box[buttonBox].inside == 'e')
        {
            all_box[buttonBox].inside = 'b';
            break;
        }
        n--;
    }
    printf("Você e seu colega de trabalho estavam explorando a tumba do faraó Neebe quando entraram em uma grande sala com escrituras na parede. Enquanto inspecionavam as escrituras, vocês acidentalmente pressionaram um botão escondido que lacrou as portas, prendendo-os lá dentro. Então, cinco caixas apareceram no centro da sala, uma delas contendo o botão para abrir as portas, mas uma delas contém uma cobra mortal! Vocês decidem jogar turnos para abrir uma caixa de cada vez, na esperança de não encontrar a cobra.\n\n");

    printf("Antes de começar coloque o seu nome: ");
    scanf("%s", players[0].name);

    printf("\n Agora, o nome do segundo jogador: ");
    scanf("%s", players[1].name);

    int end_game = 0;
    int contador = rand() % 2;
    while (end_game == 0)
    {
        int choice;
        for (int i = 0; i < 5; i++)
        {
            if (all_box[i].open == 0)
            {
                printf("%d) Caixa fechada \n", (i + 1));
            }
        }
        printf("Escolha uma caixa para abrir (1/2/3/4/5), %s: ", players[(int)ceil(contador%2)].name);

        scanf("%i", &choice);
        all_box[choice - 1].open = 1;

        printf("A caixa numero %d e dentro dela possui: %c (e = Vazia , s = Cobra, b = Botão) \n", choice, all_box[choice - 1].inside);
        if (all_box[choice - 1].inside == 's')
        {
            players[(int)ceil(contador%2)].tag = 'l';
            printf("Você perdeu a caixa tinha uma cobra\n");
            for (size_t i = 0; i < 2; i++)
            {
                if (players[i].tag != 'l')
                {
                    printf("Vencedor foi %s \n", players[i].name);
                }
                
            }
            end_game = 1;
        }
        else if (all_box[choice - 1].inside == 'b')
        {
            players[(int)ceil(contador%2)].tag = 'w';
            printf("Você ganhou, a caixa tinha o botão\n");
            for (size_t i = 0; i < 2; i++)
            {
                if (players[i].tag != 'w')
                {
                    printf("Perdedor foi %s \n", players[i].name);
                }
                
            }
            
            end_game = 1;
        }
        contador++;
    }

    return 0;
    ;
}

int main()
{
    // quiz();

    boxgame();

} // Display the
