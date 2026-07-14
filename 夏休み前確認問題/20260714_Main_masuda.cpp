#include<iostream>
#include"20260714_Header_masuda.h"
using namespace std;

int main()
{
	int player = 0;//ƒvƒŒƒCƒ„[‚Ì“ü—Í
	int enemy = 0;//‚b‚o‚t‚Ì“ü—Í
	int Random = 0;//‚b‚o‚t‚Ìƒ‰ƒ“ƒ_ƒ€‘I‘ğ
	int playercard[Card] = {};//ƒvƒŒƒCƒ„[‚ÌèD
	int enemycard[Card] = {};//‚b‚o‚t‚ÌèD
	bool playerused[Card] = {};//g—pÏ‚İ‚ÌƒJ[ƒh(ƒvƒŒƒCƒ„[)
	bool enemyused[Card] = {};//g—pÏ‚İ‚ÌƒJ[ƒh(‚b‚o‚t)
	int playerPoint = 0;//“_”(ƒvƒŒƒCƒ„[)
	int enemyPoint = 0;//“_”(‚b‚o‚t)
	int matchcount = 0;//‡‰ñ”
	int judge = 0;
	srand((int unsigned)time(NULL));

	cout << "ƒvƒŒƒCƒ„[‚Æ‚b‚o‚t‚Å‘Îí‚ğ‚µ‚æ‚¤\n"
		<< "‚O`‚T‚O‚Ü‚Å‚Ìƒ‰ƒ“ƒ_ƒ€‚È”š‚ÌèD‚ğ‚¨Œİ‚¢‚É10ŒÂ‚¸‚Â—pˆÓ‚µ‚Ü‚·\n"
		<< "ƒvƒŒƒCƒ„[‚Æ‚b‚o‚t‚Í‚¨Œİ‚¢‚ÉèD‚ğˆê–‡‘I‘ğ‚µ‚Ä”š‚Ì‘å‚«‚³‚ğ”äŠr‚µ‚Ü‚·\n"
		<< "”š‚Ì‘å‚«‚¢‚Ù‚¤‚É‚R“_A”š‚ª“¯‚¶ê‡‚Í‚¨Œİ‚¢‚É‚P“_‚ğŠl“¾‚µ‚Ü‚·\n"
		<< "‚V‰ñs‚¢‚æ‚è“_”‚Ì‘½‚¢•û‚ÌŸ—˜‚Æ‚È‚è‚Ü‚·" << endl;

	for (int i = 0; i < 10; i++)
	{
		playercard[i] = Dealcards();
		enemycard[i] = Dealcards();
	}

	while (matchcount < Maxmatch)
	{
		cout << matchcount + 1 << "‰ñ–Ú\n"
			<< "”š‚ğ‘I‘ğ‚·‚é‚Í¶‚©‚ç‰½”Ô–Ú‚Ì‚æ‚¤‚É“ü—Í‚µ‚Ä‚­‚¾‚³‚¢\n" 
			<< "{}";
		while (true)
		{
			InputCheck(player);
			if (playerused[player] != true)
			{
				break;
			}
		}
		while (true)
		{
			enemy = rand() % Card;
			if (enemyused[enemy] != true)
			{
				break;
			}
		}

		int judge = Judge(playercard[player],enemycard[enemy]);

		if (judge == 1)
		{
			playerPoint += Winpoint;
		}
		else if (judge == 0)
		{
			enemyPoint += Winpoint;
		}
		else
		{
			playerPoint += Drawpoint;
			enemyPoint += Drawpoint;
		}
		playerused[player] = true;
		enemyused[enemy] = true;

		matchcount++;
	}
}