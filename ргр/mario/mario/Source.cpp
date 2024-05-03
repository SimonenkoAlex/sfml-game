#include <SFML/Graphics.hpp>
#include <conio.h>
#include <string>
#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;

const int H = 81;
const int W = 212;

const int ts = 32;
const int vr = 39;

int lever = 1, sec = 0;
int monnet = 0, life = 3;

float offsetX = 0, offsetY = 0;
bool cam = true, win = false,
management = false, finish = false, pusla = false;

string fileGamePath = "C:/Users/User/source/repos/GitHub/sfml-game/";

String TileMap[H] = {
	"0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
	"                                                                                                                                                                                                                   ",
	"                                                                                                                                                                                                      W            ",
	"                                                                                                                                                                                            DD                     ",
	"                                                                               1        1                                                                                                  DDD                     ",
	"                      B                                                         CCCCCCCC   CCCB              B           CCC    CBBC                                                      DDDD                     ",
	"0                                                               B                                                                                                                        DDDDD                     ",
	"0                                             P0         P0                 1   1                                                        D  D          DD  D                            DDDDDD            F        ",
	"0               B   CBCBC             P0      00         00                  CBC              B     CB    B  B  B     C          CC     DD  DD        DDD  DD           CCBC           DDDDDDD                     ",
	"0                           P0        00      00         00                                                                            DDD  DDD      DDDD  DDD     P0              P0 DDDDDDDD                     ",
	"0                           00        00      00         00                             1                                             DDDD  DDDD    DDDDD  DDDD    00              00DDDDDDDDD        D            ",
	"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA  AAAAAAAAAAAAAAA   AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA",
	"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA  AAAAAAAAAAAAAAA   AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA",
	"                                                                                                                                                                                     0                             ",
	"                                                                     T                                                                                                               0                             ",
	"                                                       aa   aaaaaaa00000                                                                                                             0                   W         ",
	"                                                       aa              0                                                                                                             0                             ",
	"                                                       aa              0                                                                                                             0        DDD                  ",
	"                                                       aa    mmmmm     0                                                                                                             0       DDDD                  ",
	"                                                       aa   mmmmmmm    0                                                                                                             0      DDDDD                  ",
	"F                                                      aa   mmmmmmm    0                                                                                                             0     DDDDDD             F    ",
	"           t                                           aa   aaaaaaa    0                                                                                                             0    DDDDDDD                  ",
	"                                                       aa   aaaaaaa   0                                                                                                               P0 DDDDDDDD                  ",
	"                                                       aa   aaaaaaa   0                                                                                                               00DDDDDDDDD        D         ",
	"AAAAAAAAAAAAAAAAAAA                                    bbbbbbbbbbbbbbbbbb                                                                                                          ATAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA",
	"AAAAAAAAAAAAAAAAAAA                                    bbbbbbbbbbbbbbbbbb                                                                                                          AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA",
	"                  000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000                        000000000000000                      ",
	"            a     aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaBaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa                        aaaaaaaa  aaaaa                      ",
	"            a                                                     aa  aaaaaa  aaaa      aaaa                                                                                            aaaaa                      ",
	"            a                                                     aa  aaaaaa  aaaa 1  1 aaaa                                                                                            aaaaa                      ",
	"            a                                        mmmm       aa        aa   a    aa          mmmmmm                                                                                  aaaaa                      ",
	"            a                                                   aa        aa   a    aa                                                                                                  aaaaa                      ",
	"            a                                      a aaaa B     aa    mmmmaa   amB  aa          aaaaaa                                                         aaaaaa                   aaaaa                      ",
	"            a                      d d   B         ama  ama     aaaa  aaaaaa   aaa  aB 1    1   aaaaaa                   P0                         dd                                  aaaaa                      ",
	"            a         BBBBB      d d d d   d d     aaa  aaa       aa                aa  aaaa                       P0    00                        ddd                        aaaaaaaaaaaaaaa                      ",
	"            a                  d d d d d   d d                    aa                                               00    00    P0     aa          dddd                        aaaaaaaaaaaaaaa                      ",
	"            a                d d d d d d   d d                                              1 1                    00    00    00     aa 1       ddddd        1        1      aaaaaaaaaaaaaaa                      ",
	"            bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb   bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb  bb  bbbbbbbbbbbb         bbbbbbbb       bbbbbbbbbbbbbbb                      ",
	"            bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb   bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb  bb  bbbbbbbbbbbb         bbbbbbbb       bbbbbbbbbbbbbbb                      ",
	"                                                                                                                  a  aaaaaaaaaaaa                                                                                  ",
	"                                                                                                                  a  aaaaaaaaaaT                                                                                   ",
	"                                                                                                                  a  aaaaaaaaaaaa                                                                                  ",
	"                                                                                                                  a  aaaaaaaaaaaa                                                                                  ",
	"                                                                                                                  a            aa                                                                                  ",
	"                                                                                                                  a            aa                                                                                  ",
	"                                                                                                                  a   mmmmmmmm aa                                                                                  ",
	"                                                                                                                  a  aaaaaaaaBaaa                                                                                  ",
	"                                                                                                                  a            aa                                                                                  ",
	"                                                                                                                  a                                                                                                ",
	"                                                                                                                  a  mmmmmmmmm   0                                                                                 ",
	"                                                                                                                  bbbbbbbbbbbbbbbb                                                                                 ",
	"                                                                                                                  bbbbbbbbbbbbbbbb                                                                                 ",
	"                                       0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
	"                                                                                                                                                                                                                   ",
	"                                                              mm                                                                                                                                                   ",
	"                                                   1 mmm 1       1       1                                                                                                       W    f                            ",
	"                                                    IHHHJ         IHHHHHJ                           1      1   mm      mm mm                                           DD                                          ",
	"                                                     EEE           EEEEE    mm        mmmm           IHHHHJ                     1        1       mm                    DD                                          ",
	"                          0                          EEE           EEEEE              IHHJ            EEEE                       IHHHHHHJ                            DDDD                                          ",
	"                          0                          EEE     IHHHJ EEEEE               EE             EEEE                        EEEEEE                             DDDD                                          ",
	"                          0F                      IHHHHHHJ    EEE  EEEEE               EE       IHJ   EEEE                        EEEEEE     IHHJ  IHHJ            DDDDDD                                          ",
	"                          0                        EEEEEE     EEE  EEEEE               EE        E    EEEE                        EEEEEE      EE    EE             DDDDDD                                          ",
	"                          0                        EEEEEE  m  EEE  EEEEE             B EE        E    EEEE                 IHHJ   EEEEEE      EE    EE             DDDDDD                                          ",
	"                          0                  IHHJ  EEEEEE IHJ EEE  EEEEE               EE        E    EEEE        IHHJ      EE    EEEEEE  mmm EE    EE   1         DDDDDD        D                                 ",
	"                           AAAAAAAAAAAAAAAA   EE   EEEEEE  E  EEE  EEEEE    IHHJ     IHHHJ IHHHJ E    EEEE         EE       EE    EEEEEE  IHJ EE    EE    AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA                    ",
	"                           AAAAAAAAAAAAAAAA   EE   EEEEEE  E  EEE  EEEEE     EE       EEE   EEE  E    EEEE         EE       EE    EEEEEE   E  EE    EE    AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA                    ",
	"                                                                                                                                                                                                                   ",
	"                                                                                                                                                                                                                   ",
	"                              eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee              ",
	"                              eeeeeeeeeeeeeeeeeeeeee             eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee        e        e     eeeeeee                   eeeee             eee                         0              ",
	"                              eeeeeeeeeeeeeeeeeeeeee             eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee        M        M     eeeeeee                   eeeee             eee                         0              ",
	"                             0                     e                M        M          M      M                                      B  B  B                                                       0              ",
	"                              eee                     M      B                                                                                                          p                           0              ",
	"                              eeee                               1                                   1                                                    1      2     oeee                         0              ",
	"                              eeeee                1              eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee                       1        B  B  B   eeee   eeeeennnnnnnnnnnnneee                         0              ",
	"                              eeeeeeeeeeeee  eeeeeeeee   eMe   eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee   M       M       M   eeeeeee            eeee   eeeee             eee                         0              ",
	"                              eeeeeeeeeeeee  eeeeeeeee   eee   eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee            eeee   eeeee             eee                         0              ",
	"                              eeeeeeeeeeeeekkeeeeeeeeekkkeeekkkeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeekkkkkkkkkkkkkeeeeeeeeeeeeeeeeeeeeeeeeeeeee              ",
	"                              eeeeeeeeeeeeelleeeeeeeeellleeellleeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeellllllllllllleeeeeeeeeeeeeeeeeeeeeeeeeeeee              ",
	"                              eeeeeeeeeeeeelleeeeeeeeellleeellleeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeellllllllllllleeeeeeeeeeeeeeeeeeeeeeeeeeeee              ",
	"zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz",
};

class setSound {
public:
	SoundBuffer s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12;
	Sound button, jump, destroy, addlife, bonus, kill, uron, GO,
		trub, win, finish, pause;
	Music music, ML2, ML4;
	bool tr;

	setSound() {
		// C:\Users\User\source\repos\ргр\Game
		s1.loadFromFile("C:/Users/User/source/repos/ргр/Game/Sound/button.ogg");
		s2.loadFromFile("C:/Users/User/source/repos/ргр/Game/Sound/Jump.ogg");
		s3.loadFromFile("C:/Users/User/source/repos/ргр/Game/Sound/DestroyBlock.ogg");
		s4.loadFromFile("C:/Users/User/source/repos/ргр/Game/Sound/AddLife.ogg");
		s5.loadFromFile("C:/Users/User/source/repos/ргр/Game/Sound/bonus.ogg");
		s6.loadFromFile("C:/Users/User/source/repos/ргр/Game/Sound/kill.ogg");
		s7.loadFromFile("C:/Users/User/source/repos/ргр/Game/Sound/uron.ogg");
		s8.loadFromFile("C:/Users/User/source/repos/ргр/Game/Sound/GameOver.ogg");
		s9.loadFromFile("C:/Users/User/source/repos/ргр/Game/Sound/trub.ogg");
		s10.loadFromFile("C:/Users/User/source/repos/ргр/Game/Sound/win.ogg");
		s11.loadFromFile("C:/Users/User/source/repos/ргр/Game/Sound/finish.ogg");
		s12.loadFromFile("C:/Users/User/source/repos/ргр/Game/Sound/pause.ogg");

		button.setBuffer(s1);
		jump.setBuffer(s2);
		destroy.setBuffer(s3);
		addlife.setBuffer(s4);
		bonus.setBuffer(s5);
		kill.setBuffer(s6);
		uron.setBuffer(s7);
		GO.setBuffer(s8);
		trub.setBuffer(s9);
		win.setBuffer(s10);
		finish.setBuffer(s11);
		pause.setBuffer(s12);

		tr = false;

		music.openFromFile("C:/Users/User/source/repos/ргр/Game/Sound/MusicGame.ogg");
		ML2.openFromFile("C:/Users/User/source/repos/ргр/Game/Sound/ML2.ogg");
		ML4.openFromFile("C:/Users/User/source/repos/ргр/Game/Sound/ML4.ogg");

		music.setVolume(25);
		music.setLoop(true);
		ML2.setLoop(true);
		ML4.setLoop(true);
	}
};

setSound sound;

class SetMenu {
public:
	Texture t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13,
		t14, t15, t16, t17, t18, t19, t20, t21;
	Sprite screen, naz, butplay, exit, nastroy, pod, naspod, next,
		gal, npok, back, urav[4], nalev, hep, urpro, naczan, sledur,
		butmen, ki, nadpause, prod;
	bool menu, setting, ad, gl, game, blv[4], play, puskgame, help,
		win, die, pause;
	int px, bx;

	SetMenu() {
		t1.loadFromFile(fileGamePath + "ргр/Game/Menu/screen.png");
		t2.loadFromFile(fileGamePath + "ргр/Game/Menu/naz.png");
		t3.loadFromFile(fileGamePath + "ргр/Game/Menu/butplay.png");
		t4.loadFromFile(fileGamePath + "/ргр/Game/Menu/exit.png");
		t5.loadFromFile("C:/Users/User/source/repos/ргр/Game/Menu/nastroy.png");
		t6.loadFromFile("C:/Users/User/source/repos/ргр/Game/Menu/pod.png");
		t7.loadFromFile("C:/Users/User/source/repos/ргр/Game/Menu/naspod.png");
		t8.loadFromFile("C:/Users/User/source/repos/ргр/Game/Menu/npok.png");
		t9.loadFromFile("C:/Users/User/source/repos/ргр/Game/Menu/gal.png");
		t10.loadFromFile("C:/Users/User/source/repos/ргр/Game/Menu/back.png");
		t11.loadFromFile("C:/Users/User/source/repos/ргр/Game/Menu/urav.png");
		t12.loadFromFile("C:/Users/User/source/repos/ргр/Game/Menu/nalev.png");
		t13.loadFromFile("C:/Users/User/source/repos/ргр/Game/Menu/hep.png");
		t14.loadFromFile("C:/Users/User/source/repos/ргр/Game/Menu/next.png");
		t15.loadFromFile("C:/Users/User/source/repos/ргр/Game/Menu/urpro.png");
		t16.loadFromFile("C:/Users/User/source/repos/ргр/Game/Menu/naczan.png");
		t17.loadFromFile("C:/Users/User/source/repos/ргр/Game/Menu/sledur.png");
		t18.loadFromFile("C:/Users/User/source/repos/ргр/Game/Menu/butmen.png");
		t19.loadFromFile("C:/Users/User/source/repos/ргр/Game/Menu/ki.png");
		t20.loadFromFile("C:/Users/User/source/repos/ргр/Game/Menu/nadpause.png");
		t21.loadFromFile("C:/Users/User/source/repos/ргр/Game/Menu/prod.png");

		screen.setTexture(t1);
		naz.setTexture(t2);
		butplay.setTexture(t3);
		exit.setTexture(t4);
		nastroy.setTexture(t5);
		pod.setTexture(t6);
		naspod.setTexture(t7);
		npok.setTexture(t8);
		gal.setTexture(t9);
		back.setTexture(t10);
		nalev.setTexture(t12);
		hep.setTexture(t13);
		next.setTexture(t14);
		urpro.setTexture(t15);
		naczan.setTexture(t16);
		sledur.setTexture(t17);
		butmen.setTexture(t18);
		ki.setTexture(t19);
		nadpause.setTexture(t20);
		prod.setTexture(t21);

		blv[0] = true;
		for (int i = 0; i < 4; i++) {
			if (i > 0)
				blv[i] = false;
			urav[i].setTexture(t11);
			urav[i].setPosition(130 + 150 * i, 150);
		}

		naz.setPosition(6 * ts - 8, ts - 8);
		butplay.setPosition(100, 150);
		exit.setPosition(500, 150);
		nastroy.setPosition(243, 250);
		npok.setPosition(400, 50);
		gal.setPosition(700, 90);
		nalev.setPosition(275, 50);
		hep.setPosition(225, 100);
		next.setPosition(600, 360);
		urpro.setPosition(210, 100);
		naczan.setPosition(100, 200);
		sledur.setPosition(400, 200);
		butmen.setPosition(250, 300);
		ki.setPosition(210, 100);
		nadpause.setPosition(335, 100);
		prod.setPosition(450, 200);

		menu = true;
		setting = false;
		ad = true;
		gl = false;
		game = false;
		play = false;
		help = false;
		win = false;
		die = false;
		pause = false;

		px = 30;
	}

	void update() {
		if (!ad && px <= 150)
			px += 10;
		else if (ad && px >= 30)
			px -= 10;

		naspod.setPosition(px, 158);
		if (gl)
			gal.setTextureRect(IntRect(50, 0, 50, 50));
		else
			gal.setTextureRect(IntRect(0, 0, 50, 50));

		back.setPosition(30, bx);

		for (int i = 0; i < 4; i++) {
			if (blv[i])
				urav[i].setTextureRect(IntRect(80 * i, 80, 80, 80));
			else if (!blv[i])
				urav[i].setTextureRect(IntRect(0, 0, 80, 80));
		}
	}
};

SetMenu menu;

class Player {
public:
	float dx, dy;
	FloatRect rect;
	bool onGround, rig, scal, lif;
	Sprite sprite;
	float curFrame;

	Player(Texture& image) {
		sprite.setTexture(image);
		rect = FloatRect(7 * ts, 8 * ts, 32, 32);
		sprite.setTextureRect(IntRect(32 * 2, 0, 32, 32));

		dx = dy = 0;
		curFrame = 2;
		rig = true;
		scal = true;
		lif = true;
	}

	void update(float time) {
		rect.left += dx * time;
		Collision(0);

		if (!onGround)
			dy = dy + 0.0005 * time;

		rect.top += dy * time;
		onGround = false;
		Collision(1);

		if ((rect.left >= 6320 && rect.top < 288 && lever == 1) ||
			(rect.left >= 6420 && rect.top < 704 && lever == 2) ||
			(rect.left >= 5645 && rect.top < 1984 && lever == 3)) {
			sound.music.stop();
			sound.win.play();

			if (lever == 1)
				rect.left = 6320;
			if (lever == 2)
				rect.left = 6420;
			if (lever == 3)
				rect.left = 5645;

			sprite.setTextureRect(IntRect(32 * 6, 0, 32, 32));

			management = false;
		}

		if (dx != 0 || lif) {
			curFrame += 0.01 * time;
			if (curFrame > 5)
				curFrame -= 4;
		}
		else if (!lif)
			sprite.setTextureRect(IntRect(32 * 5, 0, 32, 32));

		if (dx > 0) {
			if (dy == 0)
				sprite.setTextureRect(IntRect(32 * int(curFrame), 0, 32, 32));
			else
				sprite.setTextureRect(IntRect(32 * 4, 0, 32, 32));

			rig = true;
		}
		if (dx < 0) {
			if (dy == 0)
				sprite.setTextureRect(IntRect(32 * int(curFrame) + 32, 0, -32, 32));
			else
				sprite.setTextureRect(IntRect(32 * 4 + 32, 0, -32, 32));

			rig = false;
		}

		sprite.setPosition(rect.left - offsetX, rect.top - offsetY);

		dx = 0;
	}

	void Collision(float dir) {
		for (int i = rect.top / ts; i < (rect.top + rect.height) / ts; i++)
			for (int j = rect.left / ts; j < (rect.left + rect.width) / ts; j++) {
				if (((TileMap[i][j] == '0' || TileMap[i][j] == 'A' || TileMap[i][j] == 'B' || TileMap[i][j] == 'C' || TileMap[i][j] == 'P' ||
					TileMap[i][j] == 'D' || TileMap[i][j] == 'a' || TileMap[i][j] == 'b' || TileMap[i][j] == 'd' || TileMap[i][j] == 'E' ||
					TileMap[i][j] == 'H' || TileMap[i][j] == 'I' || TileMap[i][j] == 'J' || TileMap[i][j] == 'e' || TileMap[i][j] == 'M' ||
					TileMap[i][j] == 'n' || TileMap[i][j] == '3') && scal) || (TileMap[i][j] == 'z')) {
					if (dx > 0 && dir == 0)
						rect.left = j * ts - rect.width;
					if (dx < 0 && dir == 0)
						rect.left = j * ts + ts;
					if (dy > 0 && dir == 1) {
						rect.top = i * ts - rect.height;
						dy = 0;
						onGround = true;
					}
					if (dy < 0 && dir == 1) {
						rect.top = i * ts + ts;
						dy = 0;

						if (TileMap[i][j] == 'C' || TileMap[i][j] == 'a') {
							sound.destroy.play();

							if (TileMap[i][j] == 'C')
								TileMap[i][j] = '4';
							if (TileMap[i][j] == 'a')
								TileMap[i][j] = '5';

							if (TileMap[i - 1][j] == 'm') {
								TileMap[i - 1][j] = '6';
								sound.bonus.play();

								monnet++;
							}
						}

						if (TileMap[i][j] == 'B') {
							TileMap[i][j] = '3';

							if ((j == 16 && i == 8) || (j == 23 && i == 8) || (j == 22 && i == 5) ||
								(j == 94 && i == 8) || (j == 94 && i == 5) || (j == 106 && i == 8) ||
								(j == 109 && i == 8) || (j == 112 && i == 8) || (j == 129 && i == 5) ||
								(j == 130 && i == 5) || (j == 170 && i == 8) || (j == 23 && i == 34) ||
								(j == 24 && i == 34) || (j == 25 && i == 34) || (j == 26 && i == 34) ||
								(j == 41 && i == 33) || (j == 85 && i == 33) || (j == 125 && i == 46) ||
								(j == 133 && i == 74) || (j == 136 && i == 74) || (j == 139 && i == 74) ||
								(j == 134 && i == 71) || (j == 137 && i == 71) || (j == 140 && i == 71)) {
								sound.bonus.play();

								monnet++;
							}

							if ((j == 21 && i == 8) || (j == 64 && i == 6) || (j == 78 && i == 8) ||
								(j == 101 && i == 8) || (j == 109 && i == 5) || (j == 22 && i == 34) ||
								(j == 58 && i == 32) || (j == 81 && i == 32) || (j == 101 && i == 27) ||
								(j == 85 && i == 62) || (j == 85 && i == 62) || (j == 61 && i == 72)) {
								sound.addlife.play();

								life++;
							}
						}
					}
				}

				if (TileMap[i][j] == 'm') {
					sound.bonus.play();

					TileMap[i][j] = '6';

					monnet++;
				}

				if (TileMap[i][j] == 'p' && onGround) {
					sound.finish.play();
					sound.ML4.stop();

					TileMap[i][j] = '9';

					finish = true;
					management = false;
				}
			}
	}
};

class Flag {
public:
	float dy;
	FloatRect rect;
	Sprite sprite;
	int t;
	bool tim;

	void set(Texture& image, int x, int y) {
		sprite.setTexture(image);
		rect = FloatRect(x, y, ts, ts);

		dy = 0;
		t = 0;
		tim = true;
	}

	void update(float time) {
		rect.top += dy * time;
		Collision();

		if (win && tim) {
			dy = 0.2;
			tim = false;
		}
		if (!win && !tim) {
			dy = -0.2;
			tim = true;
		}

		sprite.setPosition(rect.left - offsetX, rect.top - offsetY);
	}

	void Collision() {
		for (int i = rect.top / ts; i < (rect.top + rect.height) / ts; i++)
			for (int j = rect.left / ts; j < (rect.left + rect.width) / ts; j++)
				if ((TileMap[i][j] == 'D' && win) || (TileMap[i][j] == 'W' && !win))
					dy = 0;
	}
};

class Enemy {
public:
	float dx, dy;
	FloatRect rect;
	Sprite sprite;
	float curFrame;
	bool go, Elive, draw;
	int t = 0, he, killrun, rot;

	void set(Texture& image, int x, int y, int h) {
		sprite.setTexture(image);

		he = h;

		if (he < 3) {
			rect = FloatRect(x, y - 14 * (h - 1), ts, ts);

			if (lever == 1 || lever == 3)
				sprite.setTextureRect(IntRect(0, 0, 32, 32 + 14 * (h - 1)));
			else
				sprite.setTextureRect(IntRect(0, ts, 32, 32 + 14 * (h - 1)));
		}
		else if (he == 3) {
			rect = FloatRect(x, y, 32, 28);
			sprite.setTextureRect(IntRect(0, 0, 32, 28));
		}
		else if (he == 4) {
			rect = FloatRect(x, y - 32, ts * 2, ts * 2);
			sprite.setTextureRect(IntRect(0, 0, 64, 64));
		}

		if (he < 3 || he == 4) {
			if (h == 1 || h == 4)
				dx = 0.1;
			else if (h == 2)
				dx = 0.05;
			curFrame = 0;
			go = false;
			draw = true;
			killrun = 1;
			if (he == 4)
				rot = 0;
		}
		else if (he == 3) {
			dx = 0.1;
			go = false;
		}
	}

	void update(float time) {
		if ((go && Elive && he == 1) || (he == 2 && (killrun == 1 || killrun == 3)) || (he >= 3))
			rect.left += dx * time;

		Collision();

		if (he <= 2) {
			if (Elive) {
				curFrame += 0.1;
				if (curFrame > 2)
					curFrame -= 2;
			}
			else
				curFrame = 2;

			if (he == 1) {
				if (lever == 1 || lever == 3)
					sprite.setTextureRect(IntRect(32 * int(curFrame), 0, 32, 32));
				else
					sprite.setTextureRect(IntRect(32 * int(curFrame), ts, 32, 32));
			}
			else if (he == 2) {
				if (dx < 0) {
					if (lever == 1 || lever == 3)
						sprite.setTextureRect(IntRect(32 * int(curFrame), 0, 32, 46));
					else
						sprite.setTextureRect(IntRect(32 * int(curFrame), 46, 32, 46));
				}
				if (dx > 0) {
					if (lever == 1 || lever == 3)
						sprite.setTextureRect(IntRect(32 * int(curFrame) + 32, 0, -32, 46));
					else
						sprite.setTextureRect(IntRect(32 * int(curFrame) + 32, 46, -32, 46));
				}
			}
		}
		else if (he == 4) {
			curFrame += 0.1;
			if (curFrame > 2)
				curFrame -= 2;
		}

		if (!Elive && t <= 20 && he == 1) {
			t++;

			if (t == 20)
				draw = false;
		}

		sprite.setPosition(rect.left - offsetX, rect.top - offsetY);
	}

	void Collision() {
		for (int i = rect.top / ts; i < (rect.top + rect.height) / ts; i++)
			for (int j = rect.left / ts; j < (rect.left + rect.width) / ts; j++)
				if (TileMap[i][j] == '0' || TileMap[i][j] == '1'
					|| TileMap[i][j] == 'D' || TileMap[i][j] == 'd'
					|| TileMap[i][j] == 'a' || TileMap[i][j] == 'e' || TileMap[i][j] == 'M') {
					if (dx > 0)
					{
						rect.left = j * ts - rect.width;
						dx *= -1;

						if (he == 3)
							sprite.setTextureRect(IntRect(32, 0, -32, 28));
					}
					else if (dx < 0)
					{
						rect.left = j * ts + ts;
						dx *= -1;

						if (he == 3)
							sprite.setTextureRect(IntRect(0, 0, 32, 28));
					}
				}
				else if (TileMap[i][j] == '2' && he == 4)
					pusla = true;
	}
};

class Pula {
public:
	float dx, dy;
	FloatRect rect;
	int go;
	Sprite sprite;
	float curFrame;

	Pula(Texture& image) {
		sprite.setTexture(image);

		dx = dy = 0;
		go = 0;
		curFrame = 0;
	}

	void update(float time) {
		rect.left += dx * time;
		Collision();

		rect.top += dy * time;

		curFrame += 0.1;
		if (curFrame > 2)
			curFrame -= 2;

		if (dx < 0)
			sprite.setTextureRect(IntRect(48 * int(curFrame), 0, 48, 16));
		else if (dx > 0)
			sprite.setTextureRect(IntRect(48 * int(curFrame) + 48, 0, -48, 16));

		sprite.setPosition(rect.left - offsetX, rect.top - offsetY);
	}

	void Collision() {
		for (int i = rect.top / ts; i < (rect.top + rect.height) / ts; i++)
			for (int j = rect.left / ts; j < (rect.left + rect.width) / ts; j++)
				if (TileMap[i][j] == '0' || TileMap[i][j] == 'e')
					if ((dx > 0) || (dx < 0)) {
						go = 0;

						pusla = false;
					}
	}
};

int main() {
	RenderWindow window(VideoMode(25 * ts, 13 * ts), "Super Mario!");

	Texture Picture;
	Picture.loadFromFile("C:/Users/User/source/repos/ргр/Game/Paint/mario.png");
	Player p(Picture);

	Sprite ps(Picture);
	ps.setTextureRect(IntRect(0, 0, 32, 32));
	ps.setPosition(16, 14);
	ps.setScale(1.2, 1.2);

	Texture pl;
	pl.loadFromFile("C:/Users/User/source/repos/ргр/Game/Paint/plat.png");
	Sprite plat(pl);

	Sprite mon(pl);
	mon.setPosition(21 * ts, 14);
	mon.setScale(1.5, 1.5);
	mon.setTextureRect(IntRect(ts * 5, 0, ts, ts));

	Texture sc;
	sc.loadFromFile("C:/Users/User/source/repos/ргр/Game/Paint/score.png");
	Sprite score[4];
	for (int i = 0; i < 4; i++) {
		score[i].setTexture(sc);
		if (i < 2) {
			score[i].setTextureRect(IntRect(22 * monnet, 0, 22, 45));
			score[i].setPosition(22 * ts + 17 + 30 * i, 15);
		}
		else if (i == 2) {
			score[i].setTextureRect(IntRect(22 * life, 0, 22, 45));
			score[i].setPosition(ts * 2, 10);
		}
		else if (i == 3) {
			score[i].setTextureRect(IntRect(22 * lever, 0, 22, 45));
			score[i].setPosition(ts * 16 + 16, 10);
		}
	}

	Texture en, eny, tf, bs;
	en.loadFromFile("C:/Users/User/source/repos/ргр/Game/Paint/enemy.png");
	eny.loadFromFile("C:/Users/User/source/repos/ргр/Game/Paint/emyche.png");
	tf.loadFromFile("C:/Users/User/source/repos/ргр/Game/Paint/fire.png");
	bs.loadFromFile("C:/Users/User/source/repos/ргр/Game/Paint/boss.png");

	Enemy enemy[vr];

	//Грибы
	{
		enemy[0].set(en, ts * 27, ts * 10, 1);
		enemy[1].set(en, ts * 45, ts * 10, 1);
		enemy[2].set(en, ts * 56, ts * 10, 1);
		enemy[3].set(en, ts * 54, ts * 10, 1);
		enemy[4].set(en, ts * 79, ts * 7, 1);
		enemy[5].set(en, ts * 87, ts * 4, 1);
		enemy[6].set(en, ts * 107, ts * 10, 1);
		enemy[7].set(en, ts * 107, ts * 10, 1);
		enemy[7].set(en, ts * 109, ts * 10, 1);
		enemy[8].set(en, ts * 131, ts * 10, 1);
		enemy[9].set(en, ts * 133, ts * 10, 1);
		enemy[10].set(en, ts * 176, ts * 10, 1);
		enemy[11].set(en, ts * 178, ts * 10, 1);
		enemy[12].set(en, ts * 28, ts * 36, 1);
		enemy[13].set(en, ts * 27, ts * 36, 1);
		enemy[14].set(en, ts * 42, ts * 36, 1);
		enemy[15].set(en, ts * 91, ts * 36, 1);
		enemy[16].set(en, ts * 85, ts * 36, 1);
		enemy[17].set(en, ts * 85, ts * 29, 1);
		enemy[18].set(en, ts * 91, ts * 33, 1);
		enemy[19].set(en, ts * 112, ts * 36, 1);
		enemy[20].set(en, ts * 110, ts * 36, 1);
		enemy[21].set(en, ts * 108, ts * 36, 1);
		enemy[22].set(en, ts * 126, ts * 36, 1);
		enemy[23].set(en, ts * 144, ts * 36, 1);
		enemy[24].set(en, ts * 142, ts * 36, 1);
		enemy[25].set(en, ts * 72, ts * 55, 1);
		enemy[26].set(en, ts * 70, ts * 55, 1);
		enemy[27].set(en, ts * 106, ts * 56, 1);
	}

	//Черепахи
	{
		enemy[28].set(eny, ts * 133, ts * 10, 2);
		enemy[29].set(eny, ts * 91, ts * 36, 2);
		enemy[30].set(eny, ts * 166, ts * 36, 2);
		enemy[31].set(eny, ts * 56, ts * 55, 2);
		enemy[32].set(eny, ts * 136, ts * 57, 2);
		enemy[33].set(eny, ts * 162, ts * 63, 2);
	}

	//Огненные линии
	{
		enemy[34].set(tf, ts * 65 + 2, ts * 74, 3);
		enemy[35].set(tf, ts * 77 + 2, ts * 73, 3);
		enemy[36].set(tf, ts * 104 + 2, ts * 74, 3);
		enemy[37].set(tf, ts * 118 + 2, ts * 70, 3);
	}

	enemy[38].set(bs, ts * 166, ts * 73, 4);

	Texture fp;
	fp.loadFromFile("C:/Users/User/source/repos/ргр/Game/Paint/pula.png");
	Pula pu(fp);

	Texture fr;
	fr.loadFromFile("C:/Users/User/source/repos/ргр/Game/Paint/frend.png");
	Sprite frend(fr);
	Clock clock;

	Texture fl;
	fl.loadFromFile("C:/Users/User/source/repos/ргр/Game/Paint/flag.png");
	Flag flag[3];
	flag[0].set(fl, 198 * ts - 18, 2 * ts + 18);
	flag[1].set(fl, 201 * ts - 18, 15 * ts + 18);
	flag[2].set(fl, 177 * ts - 18, 56 * ts + 18);

	Texture tl;
	tl.loadFromFile("C:/Users/User/source/repos/ргр/Game/Paint/TextLever.png");
	Sprite TextLever(tl);

	TextLever.setPosition(8 * ts, 12);

	bool black = false, bonus = false;
	int LV = 0;

	sound.music.play();

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();

			if (event.type == Event::MouseButtonPressed)
				if (event.key.code == Mouse::Left) {
					Vector2i pos = Mouse::getPosition(window);

					if (menu.menu) {
						if (menu.exit.getGlobalBounds().contains(pos.x, pos.y)) {
							sound.button.play();

							window.close();
						}

						if (menu.nastroy.getGlobalBounds().contains(pos.x, pos.y)) {
							sound.button.play();

							menu.menu = false;
							menu.setting = true;

							menu.bx = 250;

							menu.pod.setPosition(20, 50);
							menu.pod.setTextureRect(IntRect(0, 0, 277, 100));
						}

						if (menu.butplay.getGlobalBounds().contains(pos.x, pos.y)) {
							sound.button.play();

							menu.menu = false;
							menu.game = true;

							menu.bx = 360;
						}
					}
					else if (menu.setting) {
						if (pos.x >= 158 && pos.x <= 316 &&
							pos.y >= 50 && pos.y <= 188 &&
							menu.ad) {
							sound.button.play();

							menu.ad = false;
						}
						if (pos.x >= 20 && pos.x <= 158 &&
							pos.y >= 50 && pos.y <= 188 &&
							!menu.ad) {
							sound.button.play();

							menu.ad = true;
						}

						if (menu.gal.getGlobalBounds().contains(pos.x, pos.y)) {
							sound.button.play();

							if (!menu.gl)
								menu.gl = true;
							else
								menu.gl = false;
						}

						if (menu.back.getGlobalBounds().contains(pos.x, pos.y)) {
							sound.button.play();

							menu.setting = false;
							menu.menu = true;
						}
					}
					else if (menu.game) {
						if (menu.back.getGlobalBounds().contains(pos.x, pos.y)) {
							sound.button.play();

							menu.game = false;
							menu.menu = true;
						}

						for (int i = 0; i < 4; i++)
							if (menu.urav[i].getGlobalBounds().contains(pos.x, pos.y) && menu.blv[i]) {
								sound.button.play();

								menu.game = false;
								LV = i;
								if (menu.gl)
									menu.puskgame = true;
								else if (!menu.gl) {
									menu.help = true;

									if (menu.ad)
										menu.pod.setTextureRect(IntRect(0, 0, 138, 100));
									else if (!menu.ad)
										menu.pod.setTextureRect(IntRect(138, 0, 138, 100));
									menu.pod.setPosition(325, 170);
								}
							}
					}
					else if (menu.help) {
						if (menu.back.getGlobalBounds().contains(pos.x, pos.y)) {
							sound.button.play();

							menu.help = false;
							menu.game = true;
						}

						if (menu.next.getGlobalBounds().contains(pos.x, pos.y)) {
							sound.button.play();

							menu.help = false;
							menu.puskgame = true;
						}
					}
					else if (menu.win || menu.die || menu.pause) {
						if (menu.naczan.getGlobalBounds().contains(pos.x, pos.y)) {
							sound.button.play();
							sound.win.stop();
							sound.GO.stop();
							sound.music.stop();
							sound.ML2.stop();
							sound.ML4.stop();

							menu.puskgame = true;
						}

						if (menu.win) {
							if (menu.sledur.getGlobalBounds().contains(pos.x, pos.y) && lever < 4 && !menu.die) {
								sound.win.stop();
								sound.GO.stop();
								sound.button.play();

								menu.puskgame = true;
								LV++;
							}
						}
						else if (menu.pause)
							if (menu.prod.getGlobalBounds().contains(pos.x, pos.y)) {
								sound.win.stop();
								sound.button.play();

								if (!black)
									sound.music.play();
								else if (black && lever < 4)
									sound.ML2.play();
								else if (lever == 4)
									sound.ML4.play();

								menu.pause = false;
							}

						if (menu.butmen.getGlobalBounds().contains(pos.x, pos.y)) {
							sound.win.stop();
							sound.GO.stop();
							sound.button.play();

							sound.ML4.stop();
							sound.ML2.stop();
							sound.music.play();

							menu.win = false;
							menu.play = false;
							menu.menu = true;
						}
					}
				}
		}

		if (win && ((lever == 1 && p.rect.left >= 6500) ||
			(lever == 2 && p.rect.left >= 6640) ||
			(lever == 3 && p.rect.left >= 5940) ||
			(lever == 4 && p.rect.left >= 5850))) {
			menu.win = true;

			if (lever < 4)
				menu.blv[lever] = true;
		}

		if (menu.puskgame) {
			menu.puskgame = false;
			menu.win = false;
			menu.die = false;
			menu.pause = false;

			p.lif = true;
			p.scal = true;

			menu.game = false;
			menu.play = true;
			management = true;

			win = false;
			finish = false;
			cam = true;

			lever = LV + 1;

			if (lever < 4) {
				sound.music.play();
				sound.ML4.stop();
			}
			else if (lever == 4) {
				sound.music.stop();
				sound.ML4.play();
			}

			monnet = 0;
			life = 3;
			score[0].setTextureRect(IntRect(0, 0, 22, 45));

			for (int i = 0; i < H; i++)
				for (int j = 0; j < W; j++) {
					if (TileMap[i][j] == '3')
						TileMap[i][j] = 'B';
					if (TileMap[i][j] == '4')
						TileMap[i][j] = 'C';
					if (TileMap[i][j] == '5')
						TileMap[i][j] = 'a';
					if (TileMap[i][j] == '6')
						TileMap[i][j] = 'm';
					if (TileMap[i][j] == '7')
						TileMap[i][j] = 'n';
					if (TileMap[i][j] == '8')
						TileMap[i][j] = 'o';
					if (TileMap[i][j] == '9')
						TileMap[i][j] = 'p';
				}

			for (int i = 0; i < vr; i++) {
				enemy[i].go = false;
				enemy[i].Elive = true;
				enemy[i].draw = true;
				enemy[i].t = 0;
				enemy[i].killrun = 1;

				if (enemy[i].he == 1 || enemy[i].he == 4)
					enemy[i].dx = 0.1;
				else if (enemy[i].he == 2)
					enemy[i].dx = 0.05;
			}

			//Грибы
			{
				enemy[0].rect.left = ts * 27; enemy[0].rect.top = ts * 10;
				enemy[1].rect.left = ts * 45; enemy[1].rect.top = ts * 10;
				enemy[2].rect.left = ts * 56; enemy[2].rect.top = ts * 10;
				enemy[3].rect.left = ts * 54; enemy[3].rect.top = ts * 10;
				enemy[4].rect.left = ts * 79; enemy[4].rect.top = ts * 7;
				enemy[5].rect.left = ts * 87; enemy[5].rect.top = ts * 4;
				enemy[6].rect.left = ts * 107; enemy[6].rect.top = ts * 10;
				enemy[7].rect.left = ts * 107; enemy[7].rect.top = ts * 10;
				enemy[7].rect.left = ts * 109; enemy[7].rect.top = ts * 10;
				enemy[8].rect.left = ts * 131; enemy[8].rect.top = ts * 10;
				enemy[9].rect.left = ts * 133; enemy[9].rect.top = ts * 10;
				enemy[10].rect.left = ts * 176; enemy[10].rect.top = ts * 10;
				enemy[11].rect.left = ts * 178; enemy[11].rect.top = ts * 10;
				enemy[12].rect.left = ts * 28; enemy[12].rect.top = ts * 36;
				enemy[13].rect.left = ts * 25; enemy[13].rect.top = ts * 36;
				enemy[14].rect.left = ts * 42; enemy[14].rect.top = ts * 36;
				enemy[15].rect.left = ts * 91; enemy[15].rect.top = ts * 36;
				enemy[16].rect.left = ts * 85; enemy[16].rect.top = ts * 36;
				enemy[17].rect.left = ts * 85; enemy[17].rect.top = ts * 29;
				enemy[18].rect.left = ts * 91; enemy[18].rect.top = ts * 33;
				enemy[19].rect.left = ts * 112; enemy[19].rect.top = ts * 36;
				enemy[20].rect.left = ts * 110; enemy[20].rect.top = ts * 36;
				enemy[21].rect.left = ts * 108; enemy[21].rect.top = ts * 36;
				enemy[22].rect.left = ts * 126; enemy[22].rect.top = ts * 36;
				enemy[23].rect.left = ts * 144; enemy[23].rect.top = ts * 36;
				enemy[24].rect.left = ts * 142; enemy[24].rect.top = ts * 36;
				enemy[25].rect.left = ts * 72; enemy[25].rect.top = ts * 55;
				enemy[26].rect.left = ts * 70; enemy[26].rect.top = ts * 55;
				enemy[27].rect.left = ts * 106; enemy[27].rect.top = ts * 56;
			}

			//Черепахи
			{
				enemy[28].rect.left = ts * 133; enemy[28].rect.top = ts * 10 - 14;
				enemy[29].rect.left = ts * 91; enemy[29].rect.top = ts * 36 - 14;
				enemy[30].rect.left = ts * 166; enemy[30].rect.top = ts * 36 - 14;
				enemy[31].rect.left = ts * 56; enemy[31].rect.top = ts * 55 - 14;
				enemy[32].rect.left = ts * 136; enemy[32].rect.top = ts * 57 - 14;
				enemy[33].rect.left = ts * 162; enemy[33].rect.top = ts * 63 - 14;
			}

			//Огненные линии
			{
				enemy[34].rect.left = ts * 65 + 2; enemy[34].rect.top = ts * 74;
				enemy[35].rect.left = ts * 77 + 2; enemy[35].rect.top = ts * 73;
				enemy[36].rect.left = ts * 104 + 2; enemy[36].rect.top = ts * 74;
				enemy[37].rect.left = ts * 114 + 2; enemy[37].rect.top = ts * 70;
			}

			enemy[38].rect.left = ts * 166; enemy[38].rect.top = ts * 73 - 32;

			switch (lever)
			{
			case 1:
				black = false;

				p.rect.top = 10 * ts;
				p.rect.left = 8 * ts;

				offsetX = 0;
				offsetY = 0;
				break;
			case 2:
				sound.tr = true;

				black = false;

				offsetX = 0;
				offsetY = 416;

				p.rect.left = 65;
				p.rect.top = 736;
				break;
			case 3:
				black = false;

				offsetX = 864;
				offsetY = 1696;

				p.rect.left = 932;
				p.rect.top = 2016;

				management = true;
				break;
			case 4:
				black = true;

				offsetX = 960;
				offsetY = 2112;

				p.rect.left = 1002;
				p.rect.top = 2272;

				management = true;
				black = true;
				break;
			}
		}

		if (!_kbhit())
			if (p.onGround) {
				if (p.rig)
					p.sprite.setTextureRect(IntRect(0, 0, 32, 32));
				else if (!p.rig)
					p.sprite.setTextureRect(IntRect(32, 0, -32, 32));
			}

		if (management && p.lif && !menu.die && !menu.pause) {
			if ((Keyboard::isKeyPressed(Keyboard::Left) && !menu.ad) ||
				(Keyboard::isKeyPressed(Keyboard::A) && menu.ad))
				p.dx = -0.3;
			if ((Keyboard::isKeyPressed(Keyboard::Right) && !menu.ad) ||
				(Keyboard::isKeyPressed(Keyboard::D) && menu.ad))
				p.dx = 0.3;

			if ((Keyboard::isKeyPressed(Keyboard::Up) && !menu.ad) ||
				(Keyboard::isKeyPressed(Keyboard::W) && menu.ad))
				if (p.onGround) {
					sound.jump.play();

					p.dy = -0.4;

					p.onGround = false;

					if (p.rig)
						p.sprite.setTextureRect(IntRect(32 * 4, 0, 32, 32));
					else if (!p.rig)
						p.sprite.setTextureRect(IntRect(32 * 4 + 32, 0, -32, 32));
				}
		}

		if (Keyboard::isKeyPressed(Keyboard::Escape) && !win && !menu.die && !menu.pause && menu.play) {
			sound.music.pause();
			sound.ML2.pause();
			sound.ML4.pause();
			sound.pause.play();

			menu.pause = true;
		}

		//Движок
		{
			//Движок камеры
			{
				if (lever == 1) {
					if (p.rect.left > 400 && p.rect.left < 6352 && cam)
						offsetX = p.rect.left - 400;

					if (p.rect.left >= 1821 && p.rect.left <= 1887 &&
						p.rect.top >= 448 && p.rect.top <= 480) {
						sound.ML2.play();

						p.scal = true;
						cam = false;
						black = true;
						management = true;

						offsetX = 1640;
						offsetY = 448;
					}
				}
				else if (lever == 2) {
					if (cam && ((p.rect.left > 784 && p.rect.left <= 5646) ||
						(p.rect.left > 5705 && p.rect.left < 6354 && !black))) {
						offsetX = p.rect.left - 400;

						if (offsetX < 5728 && !black)
							offsetX = 5728;
					}

					if (p.rect.left >= 3678 && p.rect.left <= 3710 &&
						p.rect.top >= 1248 && p.rect.top <= 1280) {
						sound.ML2.play();

						p.scal = true;
						management = true;

						offsetX = 3500;
						offsetY = 1250;

						cam = false;
					}
				}
				else if (lever == 3) {
					if (p.rect.left > 1260 && p.rect.left < 5713)
						offsetX = p.rect.left - 400;
				}
				else if (lever == 4) {
					if (p.rect.left > 1356 && p.rect.left < 5073 && !finish)
						offsetX = p.rect.left - 400;
					if (offsetX < 5472 && finish)
						offsetX += 8;
				}
			}

			//Движок игрока
			{
				if (lever == 1) {
					if ((Keyboard::isKeyPressed(Keyboard::Down) && !menu.ad) ||
						(Keyboard::isKeyPressed(Keyboard::S) && menu.ad)) {
						if (p.rect.left >= 1828 && p.rect.left <= 1853 &&
							p.rect.top == 192 && p.scal) {
							sound.music.stop();
							sound.trub.play();
							sound.tr = true;

							p.scal = false;
							management = false;
						}
					}

					if (p.rect.left >= 2144 && p.rect.top == 736) {
						if (p.rect.left >= 2173 && sound.tr) {
							sound.ML2.stop();
							sound.trub.play();

							sound.tr = false;
						}

						p.dx = 0.1;
						management = false;
					}

					if (p.rect.left >= 6320 && p.rect.left <= 6530 &&
						p.rect.top >= 288) {
						p.dx = 0.2;

						win = true;
					}
				}
				else if (lever == 2) {
					if (p.rect.left >= 40 &&
						p.rect.left <= 416 && p.rect.top == 736) {
						if (p.rect.left >= 342 && sound.tr) {
							sound.music.stop();
							sound.trub.play();

							sound.tr = false;
						}

						p.dx = 0.2;
					}

					if (p.rect.left >= 416 && p.rect.left < 784 && p.rect.top == 736)
						p.scal = false;

					if ((Keyboard::isKeyPressed(Keyboard::Down) && !menu.ad) ||
						(Keyboard::isKeyPressed(Keyboard::S) && menu.ad))
						if (p.rect.left >= 3684 && p.rect.left <= 3714 && p.scal && !bonus) {
							sound.ML2.stop();
							sound.trub.play();
							sound.tr = true;

							p.scal = false;

							management = false;
							bonus = true;
						}

					if (p.rect.left >= 4022 && p.rect.top == 1568) {
						if (p.rect.left >= 4054 && sound.tr) {
							sound.ML2.stop();
							sound.trub.play();
							sound.tr = false;
						}
						p.dx = 0.2;

						management = false;
					}

					if (p.rect.left >= 5474 && p.rect.left <= 5506)
						sound.tr = true;

					if (p.rect.left >= 5538 && p.rect.top == 1056) {
						if (p.rect.left >= 5750 && sound.tr) {
							sound.ML2.stop();
							sound.trub.play();

							sound.tr = false;
						}

						p.dx = 0.2;

						management = false;
					}

					if (p.rect.left >= 6420 && p.rect.left <= 6660 &&
						p.rect.top >= 704) {
						p.dx = 0.2;

						win = true;
					}
				}
				else if (lever == 3) {
					if (p.rect.left >= 5645 && p.rect.left <= 5940 &&
						p.rect.top >= 1984) {
						p.dx = 0.2;

						win = true;
					}
				}
				else if (lever == 4) {
					if (p.rect.left <= 5851 && finish)
						p.dx = 0.2;
				}
			}

			//Движжок камеры и игрока
			{
				if (lever == 1) {
					if (p.rect.left == 2208 && p.rect.top == 736) {
						sound.music.play();

						black = false;
						management = true;
						cam = true;

						p.rect.left = 5226;
						p.rect.top = 256;

						offsetX = 4832;
						offsetY = 0;

						enemy[10].rect.left = ts * 176 + 18;
						enemy[11].rect.left = ts * 178;
					}

					if (p.rect.top >= 448 && !black) {
						if (life > 0) {
							life--;

							if (life == 0) {
								sound.music.stop();
								sound.ML2.stop();
								sound.ML4.stop();
								sound.GO.play();
							}
						}

						if (life != 0) {
							if (p.rect.left >= 32 && p.rect.left <= 864) {
								p.lif = true;
								p.scal = true;

								p.rect.left = 517;
								p.rect.top = 224;

								offsetX = 117;
							}
							else if (p.rect.left >= 1227 && p.rect.left <= 1792) {
								p.lif = true;
								p.scal = true;

								p.rect.left = 1230;
								p.rect.top = 224;

								offsetX = 930;
							}
							else if (p.rect.left >= 1896 && p.rect.left <= 2823) {
								p.lif = true;
								p.scal = true;

								p.rect.left = 1896;
								p.rect.top = 320;

								offsetX = 1496;
							}
							else if (p.rect.left >= 2855 && p.rect.left <= 4256) {
								p.lif = true;
								p.scal = true;

								p.rect.left = 2913;
								p.rect.top = 128;

								offsetX = 2513;
							}
							else if (p.rect.left >= 5248 && p.rect.left <= 5727) {
								p.lif = true;
								p.scal = true;

								p.rect.left = 5226;
								p.rect.top = 256;

								offsetX = 4832;
							}
						}
						else
							menu.die = true;
					}
				}
				else if (lever == 2) {
					if (p.rect.left >= 416 && p.rect.left <= 796 && p.rect.top == 736) {
						sound.ML2.play();

						black = true;
						management = true;
						p.scal = true;

						offsetX = 384;
						offsetY = 832;

						p.rect.left = 475;
						p.rect.top = 832;
					}

					if (p.rect.left == 4096 && p.rect.top == 1568) {
						sound.ML2.play();

						offsetX = 3677;
						offsetY = 832;

						p.rect.left = 4081;
						p.rect.top = 1088;

						cam = true;
						management = true;
						bonus = false;
					}

					if (p.rect.left == 5856 && p.rect.top == 1056) {
						sound.music.play();

						black = false;
						management = true;

						offsetY = 416;
						offsetX = 5728;

						p.rect.left = 5834;
						p.rect.top = 672;

						cam = true;
					}

					if (p.rect.top >= 1216 && !bonus) {
						if (life > 0) {
							life--;

							if (life == 0) {
								sound.music.stop();
								sound.ML2.stop();
								sound.ML4.stop();
								sound.GO.play();
							}
						}

						if (life != 0) {
							if (p.rect.left >= 416 && p.rect.left <= 896) {
								p.lif = true;
								p.scal = true;

								p.rect.left = 777;
								p.rect.top = 1056;

								offsetX = 384;
							}

							if (p.rect.left >= 1280 && p.rect.left <= 1344) {
								p.lif = true;
								p.scal = true;

								p.rect.left = 1236;
								p.rect.top = 1056;

								offsetX = 836;
							}

							if (p.rect.left >= 1472 && p.rect.left <= 3008) {
								p.lif = true;
								p.scal = true;

								p.rect.left = 1434;
								p.rect.top = 1056;

								offsetX = 1034;
							}

							if (p.rect.left >= 3041 && p.rect.left <= 3648) {
								p.lif = true;
								p.scal = true;

								p.rect.left = 3085;
								p.rect.top = 992;

								offsetX = 2685;
							}

							if (p.rect.left >= 3936 && p.rect.left <= 4032) {
								p.lif = true;
								p.scal = true;

								p.rect.left = 3885;
								p.rect.top = 1024;

								offsetX = 3485;
							}

							if (p.rect.left >= 4191 && p.rect.left <= 4608) {
								p.lif = true;
								p.scal = true;

								p.rect.left = 4164;
								p.rect.top = 1152;

								offsetX = 3764;
							}

							if (p.rect.left >= 4751 && p.rect.left <= 5536) {
								p.lif = true;
								p.scal = true;

								p.rect.left = 4751;
								p.rect.top = 1024;

								offsetX = 4351;
							}
						}
						else
							menu.die = true;
					}
				}
				else if (lever == 3) {
					if (p.rect.top >= 2112) {
						if (life > 0) {
							life--;

							if (life == 0) {
								sound.music.stop();
								sound.ML2.stop();
								sound.ML4.stop();
								sound.GO.play();
							}
						}

						if (life != 0) {
							if (p.rect.left >= 1346 && p.rect.left <= 2020) {
								p.lif = true;
								p.scal = true;

								p.rect.left = 1326;
								p.rect.top = 2016;

								offsetX = 926;
							}

							if (p.rect.left >= 2020 && p.rect.left <= 3106) {
								p.lif = true;
								p.scal = true;

								p.rect.left = 1878;
								p.rect.top = 1984;

								offsetX = 1478;
							}

							if (p.rect.left >= 3106 && p.rect.left <= 3991) {
								p.lif = true;
								p.scal = true;

								p.rect.left = 3107;
								p.rect.top = 1888;

								offsetX = 2707;
							}

							if (p.rect.left >= 3991 && p.rect.left <= 4758) {
								p.lif = true;
								p.scal = true;

								p.rect.left = 3991;
								p.rect.top = 1952;

								offsetX = 3598;
							}

							if (p.rect.left >= 4758 && p.rect.left <= 5211) {
								p.lif = true;
								p.scal = true;

								p.rect.left = 4751;
								p.rect.top = 1888;

								offsetX = 4351;
							}
						}
						else
							menu.die = true;
					}
				}
				else if (lever == 4) {
					if (p.rect.top >= 2486) {
						if (life > 0) {
							life--;

							if (life == 0) {
								sound.music.stop();
								sound.ML2.stop();
								sound.ML4.stop();
								sound.GO.play();
							}
						}

						if (life != 0) {
							if (p.rect.left >= 1323 && p.rect.left <= 2080) {
								p.lif = true;
								p.scal = true;

								p.rect.left = 1323;
								p.rect.top = 2368;

								offsetX = 960;
							}

							if (p.rect.left >= 2120 && p.rect.left <= 3194) {
								p.lif = true;
								p.scal = true;

								p.rect.left = 1955;
								p.rect.top = 2272;

								offsetX = 1555;
							}

							if (p.rect.left >= 3232 && p.rect.left <= 3936) {
								p.lif = true;
								p.scal = true;

								p.rect.left = 3232;
								p.rect.top = 2400;

								offsetX = 2832;
							}

							if (p.rect.left >= 3972) {
								p.lif = true;
								p.scal = true;

								p.rect.left = 3972;
								p.rect.top = 2368;

								offsetX = 3562;
							}
						}
						else
							menu.die = true;
					}
				}
			}

			if (finish) {
				win = true;

				for (int i = 0; i < H; i++)
					for (int j = 0; j < W; j++)
						if (TileMap[i][j] == 'n')
							TileMap[i][j] = '7';
						else if (TileMap[i][j] == 'o')
							TileMap[i][j] = '8';

				if (enemy[38].rect.top <= 2432)
					enemy[38].rect.top += 7;
			}

			for (int i = 0; i < vr; i++) {
				if (p.rect.left + 15 * ts >= enemy[i].rect.left)
					enemy[i].go = true;

				if (p.rect.intersects(enemy[i].rect) & p.lif) {
					if (p.dy > 0 && enemy[i].he < 3 && i < 34) {
						if (enemy[i].he == 1)
							enemy[i].go = false;
						else if (enemy[i].he == 2)
							enemy[i].killrun++;

						if (enemy[i].killrun == 3)
							enemy[i].dx *= 5;

						if (enemy[i].killrun == 5)
							enemy[i].killrun = 3;

						if ((enemy[i].he == 1 && enemy[i].Elive) || enemy[i].he == 2)
							p.dy = -0.2;

						if (enemy[i].Elive) {
							sound.kill.play();

							enemy[i].Elive = false;
						}
					}
					else if (((enemy[i].Elive || (enemy[i].he == 2 && enemy[i].killrun == 3)) && p.onGround) || (i >= 34)) {
						sound.uron.play();

						p.lif = false;
						p.scal = false;
						p.dy = -0.2;
					}
				}
			}

			if (p.rect.left < pu.rect.left && p.rect.left + 48 > pu.rect.left && p.lif &&
				p.rect.top - 7 == pu.rect.top && p.rect.top + 32 > pu.rect.top && pu.go != 0) {
				sound.uron.play();

				p.lif = false;
				p.scal = false;
				p.dy = -0.2;
			}

			for (int i = 0; i < 28; i++)
				for (int j = 28; j < 34; j++) {
					if (enemy[i].rect.left < enemy[j].rect.left && enemy[i].rect.left + 32 > enemy[j].rect.left &&
						enemy[j].killrun == 3 && enemy[i].rect.top > enemy[j].rect.top - 12 && enemy[i].rect.top < enemy[j].rect.top + 32) {
						if (enemy[i].Elive)
							sound.kill.play();

						enemy[i].Elive = false;
					}
				}

			if (pusla && p.rect.left >= 3982 && !finish && lever == 4)
				if (pu.go == 0) {
					enemy[38].rot = 64;
					enemy[38].t = 20;

					if (p.rect.left < enemy[38].rect.left) {
						pu.go = 1;

						pu.rect.left = enemy[38].rect.left - 20;
						pu.rect.top = enemy[38].rect.top + 25;
					}
					else if (p.rect.left > enemy[38].rect.left) {
						pu.go = 2;

						pu.rect.left = enemy[38].rect.left - 12;
						pu.rect.top = enemy[38].rect.top + 25;
					}
				}

			if (pu.go == 0) {
				pu.rect.left = enemy[38].rect.left;
				pu.rect.top = enemy[38].rect.top;
			}
			else if (pu.go == 1)
				pu.dx = -0.5;
			else if (pu.go == 2)
				pu.dx = 0.5;

			if (enemy[38].t > 0) {
				enemy[38].t--;

				if (enemy[38].t == 0)
					enemy[38].rot = 0;
			}
		}

		//Вызвав функции update
		{
			if (!menu.pause)
				p.update(time);

			for (int i = 0; i < 3; i++)
				flag[i].update(time);

			for (int i = 0; i < vr; i++)
				if (!menu.pause)
					enemy[i].update(time);

			if (!menu.pause)
				pu.update(time);

			menu.update();
		}

		//Рисовать
		{
			//Для игры
			{
				if (monnet < 10)
					score[1].setTextureRect(IntRect(22 * monnet, 0, 22, 45));
				else {
					int mt = monnet / 10;
					int tm = monnet % 10;

					score[0].setTextureRect(IntRect(mt * 22, 0, 22, 45));
					score[1].setTextureRect(IntRect(tm * 22, 0, 22, 45));
				}

				score[2].setTextureRect(IntRect(22 * life, 0, 22, 45));
				score[3].setTextureRect(IntRect(22 * lever, 0, 22, 45));

				//Анимация босса
				if (p.rect.left < enemy[38].rect.left)
					enemy[38].sprite.setTextureRect(IntRect(64 * int(enemy[38].curFrame), enemy[38].rot, 64, 64));
				else if (p.rect.left > enemy[38].rect.left)
					enemy[38].sprite.setTextureRect(IntRect(64 * int(enemy[38].curFrame) + 64, enemy[38].rot, -64, 64));

				if (!black)
					window.clear(Color(104, 136, 255));
				else
					window.clear(Color::Black);

				if ((p.rect.left < 6330 && lever == 1) ||
					(p.rect.left >= 200 && lever == 2) ||
					(p.rect.left < 100 && lever == 3) ||
					(lever == 4) || (p.lif))
					window.draw(p.sprite);

				frend.setPosition(5915 - offsetX, 2416 - offsetY);
				window.draw(frend);

				for (int i = 0; i < H; i++)
					for (int j = 0; j < W; j++) {
						if (TileMap[i][j] == 'A')
							plat.setTextureRect(IntRect(0, 0, ts, ts));
						if (TileMap[i][j] == 'B')
							plat.setTextureRect(IntRect(ts, 0, ts, ts));
						if (TileMap[i][j] == 'C')
							plat.setTextureRect(IntRect(ts * 2, 0, ts, ts));
						if (TileMap[i][j] == 'D')
							plat.setTextureRect(IntRect(ts * 3, 0, ts, ts));
						if (TileMap[i][j] == 'P')
							plat.setTextureRect(IntRect(0, ts, ts * 2, ts * 4));
						if (TileMap[i][j] == 'W')
							plat.setTextureRect(IntRect(ts * 2, ts, ts, ts * 8));
						if (TileMap[i][j] == 'F')
							plat.setTextureRect(IntRect(ts * 7, ts, ts * 5, ts * 4));
						if (TileMap[i][j] == 'a')
							plat.setTextureRect(IntRect(ts * 4, 0, ts, ts));
						if (TileMap[i][j] == 'b')
							plat.setTextureRect(IntRect(ts * 6, 0, ts, ts));
						if (TileMap[i][j] == 'd')
							plat.setTextureRect(IntRect(ts * 17, 0, ts, ts));
						if (TileMap[i][j] == 'm')
							plat.setTextureRect(IntRect(ts * 5, 0, ts, ts));
						if (TileMap[i][j] == 'T')
							plat.setTextureRect(IntRect(ts * 3, ts, ts * 4, ts * 10));
						if (TileMap[i][j] == 'E')
							plat.setTextureRect(IntRect(ts * 7, 0, ts, ts));
						if (TileMap[i][j] == 'I')
							plat.setTextureRect(IntRect(ts * 8, 0, ts, ts));
						if (TileMap[i][j] == 'H')
							plat.setTextureRect(IntRect(ts * 9, 0, ts, ts));
						if (TileMap[i][j] == 'J')
							plat.setTextureRect(IntRect(ts * 9, 0, -ts, ts));
						if (TileMap[i][j] == 't')
							plat.setTextureRect(IntRect(ts * 7, ts * 5, ts * 4, ts * 3));
						if (TileMap[i][j] == 'f')
							plat.setTextureRect(IntRect(ts * 12, ts, ts * 9, ts * 9));
						if (TileMap[i][j] == 'e')
							plat.setTextureRect(IntRect(ts * 10, 0, ts, ts));
						if (TileMap[i][j] == 'k')
							plat.setTextureRect(IntRect(ts * 11, 0, ts, ts));
						if (TileMap[i][j] == 'l')
							plat.setTextureRect(IntRect(ts * 12, 0, ts, ts));
						if (TileMap[i][j] == 'M' || TileMap[i][j] == '3')
							plat.setTextureRect(IntRect(ts * 13, 0, ts, ts));
						if (TileMap[i][j] == 'n')
							plat.setTextureRect(IntRect(ts * 14, 0, ts, ts));
						if (TileMap[i][j] == 'o')
							plat.setTextureRect(IntRect(ts * 15, 0, ts, ts));
						if (TileMap[i][j] == 'p')
							plat.setTextureRect(IntRect(ts * 16, 0, ts, ts));
						if (TileMap[i][j] == ' ' || TileMap[i][j] == '0' ||
							TileMap[i][j] == '1' || TileMap[i][j] == '2' ||
							TileMap[i][j] == '4' || TileMap[i][j] == '5' ||
							TileMap[i][j] == '6' || TileMap[i][j] == '7' ||
							TileMap[i][j] == '8' || TileMap[i][j] == '9')
							continue;

						plat.setPosition(j * ts - offsetX, i * ts - offsetY);
						window.draw(plat);
					}

				if ((p.rect.left >= 6330 && p.rect.left < 6530 && lever == 1) ||
					((p.rect.left < 200 || (p.rect.left > 6426 &&
						p.rect.left < 6660)) && lever == 2) ||
					((p.rect.left >= 100 && p.rect.left < 5940) && lever == 3) || (!p.lif))
					window.draw(p.sprite);

				for (int i = 0; i < 3; i++)
					window.draw(flag[i].sprite);

				for (int i = 0; i < vr - 1; i++)
					if (enemy[i].draw)
						window.draw(enemy[i].sprite);
				if (enemy[38].rect.top <= 2432)
					window.draw(enemy[38].sprite);

				if (pu.go != 0)
					window.draw(pu.sprite);

				window.draw(mon);
				for (int i = 0; i < 4; i++)
					window.draw(score[i]);

				window.draw(ps);
				window.draw(TextLever);
			}

			//Для меню
			{
				if (!menu.play)
					window.draw(menu.screen);

				if (menu.menu) {
					window.draw(menu.naz);
					window.draw(menu.butplay);
					window.draw(menu.exit);
					window.draw(menu.nastroy);
				}
				else if (menu.setting) {
					window.draw(menu.pod);
					window.draw(menu.naspod);
					window.draw(menu.npok);
					window.draw(menu.gal);
					window.draw(menu.back);
				}
				else if (menu.game) {
					for (int i = 0; i < 4; i++)
						window.draw(menu.urav[i]);
					window.draw(menu.back);
					window.draw(menu.nalev);
				}
				else if (menu.help) {
					window.draw(menu.hep);
					window.draw(menu.pod);
					window.draw(menu.back);
					window.draw(menu.next);
				}
				else if (menu.win || menu.die || menu.pause) {
					if (!finish)
						menu.urpro.setTextureRect(IntRect(0, 0, 402, 42));
					else if (finish)
						menu.urpro.setTextureRect(IntRect(0, 42, 402, 42));

					if (menu.win) {
						window.draw(menu.urpro);

						if (!finish)
							window.draw(menu.sledur);
					}
					else if (menu.die)
						window.draw(menu.ki);
					else if (menu.pause) {
						window.draw(menu.nadpause);
						window.draw(menu.prod);
					}
					window.draw(menu.naczan);
					window.draw(menu.butmen);
				}
			}
		}
		window.display();
	}

	return 0;
}