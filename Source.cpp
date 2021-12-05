#include <windows.h>
#include <stdlib.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <gl/glut.h>
#include <math.h>
#include <fstream>
#include <iostream>

#define PI 3.1415526593

double count = 0; //siginifies the time count in animation i.e 1s = 60 count;
//SC_1
float cloudSC_1 = 0;
float waterLineSC_1 = 0;
float boatMoveSC_1 = 0;

//SC_2
float waterLineSC_2 = 0;
float mtnSC_2 = 0;
float cHoMoveSC_2 = 0;
float lPMoveSC_2 = 0;

//SC_3
float waterLineSC_3 = 0;
float boatBad1_MoveSC_3 = 0;
float boatBad2_MoveSC_3 = 0;

//SC_4
float waterLineSC_4 = 0;
float boatGoodMoveSC_4 = 0;

//SC_5
float boatBad1MoveSC_5 = 0;
float boatBad2MoveSC_5 = 0;
float princessMoveSC_5 = 0;
float chengHoMoveSC_5 = 0;

//SC_6
float cloudMoveSC_6 = 0;
float chengHoMoveSC_6 = 0;

//SC_7
float chengHoMoveC_x_7 = 0;
float chengHoMoveC_y_7 = 0;
float badGuyMoveSC_7 = 0;

//SC_8 no key animation

//SC_9
float lipoMoveSC_9 = 0;
float badGuyMoveSC_9 = 0;

//SC_10
float hangTuahGigaChad = 0;

//GENERIC STUFF DRAWING
void drawQuad(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	glBegin(GL_POLYGON);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glVertex2i(x3, y3);
	glVertex2i(x4, y4);
	glEnd();
}//use this for uneven shapes
void drawUnevenTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
	glBegin(GL_POLYGON);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glVertex2i(x3, y3);
	glEnd();
}
void drawRectangle(int x, int y, int w, int h) {
	glBegin(GL_POLYGON);
	glVertex2i(x, y);
	glVertex2i(x+w, y);
	glVertex2i(x+w, y-h);
	glVertex2i(x, y-h);
	glEnd();

}
void drawEllipse(float cx, float cy, float rx, float ry, int num_segments)
{
	float theta = 2 * 3.1415926 / float(num_segments);
	float c = cosf(theta);//precalculate the sine and cosine
	float s = sinf(theta);
	float t;

	float x = 1;//we start at angle = 0 
	float y = 0;

	glBegin(GL_POLYGON);
	for (int ii = 0; ii < num_segments; ii++)
	{
		//apply radius and offset
		glVertex2f(x * rx + cx, y * ry + cy);//output vertex 

		//apply the rotation matrix
		t = x;
		x = c * x - s * y;
		y = s * t + c * y;
	}
	glEnd();
}
void drawCircle(int x, int y, int r) {
	double inc = 2 * PI / 400;
	glBegin(GL_POLYGON);
	for (double theta = 0.0; theta <= 2 * PI; theta += inc) {
		glVertex2i(r * cos(theta) + x, r * sin(theta) + y);
	}
	glEnd();
}
void drawText(const char* text, int x, int y) {
	int len = (int)strlen(text);
	glRasterPos2i(x, y);
	for (int i = 0; i < len; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, (int)text[i]);
	}
}
void drawTextBig(const char* text, int x, int y) {
	int len = (int)strlen(text);
	glRasterPos2i(x, y);
	for (int i = 0; i < len; i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (int)text[i]);
	}
}
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
	glBegin(GL_TRIANGLES);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glVertex2i(x3, y3);
	glEnd();

}



//SC_1
void sky() {
	//the sky
	glColor3ub(118, 216, 246);
	glBegin(GL_POLYGON);
	glVertex2i(0, 500);
	glVertex2i(500, 500);
	glColor3ub(200, 220, 250);
	glVertex2i(500, 0);
	glVertex2i(0, 0);
	glEnd();

	//draw sun
	double inc = 2 * PI / 100;
	glColor3ub(247, 255, 9);
	glBegin(GL_POLYGON);
	for (double theta = 0.0; theta <= 2 * PI; theta += inc) {
		glVertex2i(28 * cos(theta) + 467, 28 * sin(theta) + 46);
	}
	glEnd();

	glPushMatrix();
	glTranslatef(cloudSC_1, 0, 0);
	//drawCloud-1
	glColor3ub(255, 255, 255);
	drawCircle(271-100, 36, 15);
	drawCircle(255-100, 47, 15);
	drawCircle(233-100, 44, 15);
	drawCircle(259-100, 21, 17);
	drawCircle(209-100, 45, 18);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(cloudSC_1, 0, 0);
	//drawCloud-2
	glColor3ub(255, 255, 255);
	drawCircle(298, 38, 12);
	drawCircle(316, 54, 22);
	drawCircle(282, 72, 20);
	drawCircle(251, 71, 17);
	drawCircle(224, 80, 17);
	glPopMatrix();
}
void seaWater() {

	glBegin(GL_POLYGON);
	glColor3ub(44, 200, 234);
	glVertex2i(0, 500);
	glVertex2i(500, 500);
	glVertex2i(500, 154);
	glVertex2i(0, 154);
	glEnd();
	glPushMatrix();
	glTranslatef(0, waterLineSC_1, 0);
	//line-1
	glColor3ub(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2i(117, 191);
	glVertex2i(166, 191);
	glVertex2i(166, 189);
	glVertex2i(117, 189);
	glEnd();

	//line-2
	glColor3ub(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2i(50, 259);
	glVertex2i(140, 259);
	glVertex2i(140, 257);
	glVertex2i(50, 257);
	glEnd();

	//line-3
	glColor3ub(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2i(15, 302);
	glVertex2i(78, 302);
	glVertex2i(78, 300);
	glVertex2i(15, 300);
	glEnd();

	//line-4
	glColor3ub(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2i(420, 208);
	glVertex2i(476, 208);
	glVertex2i(476, 210);
	glVertex2i(420, 210);
	glEnd();

	//line-5
	glColor3ub(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2i(322, 244);
	glVertex2i(372, 244);
	glVertex2i(372, 246);
	glVertex2i(322, 246);
	glEnd();

	//line-6
	glColor3ub(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2i(428, 366);
	glVertex2i(486, 366);
	glVertex2i(486, 368);
	glVertex2i(428, 368);
	glEnd();
	glPopMatrix();
}
void boat() {
	glPushMatrix();
	glTranslatef(0, boatMoveSC_1, 0);
	glColor3ub(193, 104, 19);
	glBegin(GL_POLYGON);
	glVertex2i(0, 500);
	glVertex2i(500, 500);
	glVertex2i(234, 200);
	glEnd();

	//boat line-1
	glColor3ub(172, 62, 27);
	glBegin(GL_POLYGON);
	glVertex2i(51, 500);
	glVertex2i(55, 500);
	glVertex2i(238, 256);
	glVertex2i(233, 255);
	glEnd();

	//boat line-2
	glColor3ub(172, 62, 27);
	glBegin(GL_POLYGON);
	glVertex2i(238, 256);
	glVertex2i(450, 500);
	glVertex2i(455, 500);
	glVertex2i(233, 257);
	glEnd();

	//boat line-3
	glColor3ub(172, 62, 27);
	glBegin(GL_POLYGON);
	glVertex2i(86, 457);
	glVertex2i(413, 457);
	glVertex2i(409, 453);
	glVertex2i(89, 453);
	glEnd();

	//boat line-4
	glColor3ub(172, 62, 27);
	glBegin(GL_POLYGON);
	glVertex2i(109, 426);
	glVertex2i(384, 426);
	glVertex2i(381, 422);
	glVertex2i(112, 422);
	glEnd();

	//boat line-5
	glColor3ub(172, 62, 27);
	glBegin(GL_POLYGON);
	glVertex2i(158, 359);
	glVertex2i(328, 359);
	glVertex2i(328, 361);
	glVertex2i(161, 361);
	glEnd();

	//boat line-6
	glColor3ub(172, 62, 27);
	glBegin(GL_POLYGON);
	glVertex2i(187, 322);
	glVertex2i(295, 322);
	glVertex2i(292, 320);
	glVertex2i(189, 320);
	glEnd();
	glPopMatrix();
}

//SC_2
void waterSC_2() {
	glColor3ub(44, 200, 234);
	glBegin(GL_POLYGON);
	glVertex2i(0, 500);
	glVertex2i(500, 500);
	glVertex2i(500, 146);
	glVertex2i(0, 146);
	glEnd();
	

	//waterLine 
	//line-1
	glPushMatrix();
	glTranslatef(waterLineSC_2, 0, 0);
	glColor3ub(0, 0, 0);
	drawRectangle(29, 180, 30, 2);
	drawRectangle(32, 161, 33, 2);
	drawRectangle(114, 163, 43, 2);
	drawRectangle(127, 180, 26, 2);
	drawRectangle(204, 169, 31, 2);
	drawRectangle(258, 181, 30, 2);
	drawRectangle(334, 157, 30, 2);
	drawRectangle(374, 172, 30, 2);
	drawRectangle(432, 157, 30, 2);
	glPopMatrix();

}
void mountainsSC_2() {
	//ground
	glColor3ub(201, 101, 21);
	drawRectangle(0, 146, 500, 10);
	//mtn-1
	glPushMatrix();
	glTranslatef(mtnSC_2, 0, 0);
	glColor3ub(58, 155, 2);
	glBegin(GL_POLYGON);	
	glVertex2i(57, 136);
	glVertex2i(146, 50);
	glVertex2i(212, 115);
	glVertex2i(188, 136);
	glEnd();

	//mtn-2
	glColor3ub(58, 196, 0);
	glBegin(GL_POLYGON);
	glVertex2i(306, 136);
	glVertex2i(402, 44);
	glVertex2i(497, 136);
	glEnd();

	//mtn-3
	glColor3ub(38, 102, 2);
	glBegin(GL_POLYGON);
	glVertex2i(0, 136);
	glVertex2i(57, 136);
	glVertex2i(109, 88);
	glVertex2i(62, 41);
	glVertex2i(0, 103);
	glEnd();

	//mtn-4
	glColor3ub(38, 102, 2);
	glBegin(GL_POLYGON);
	glVertex2i(212, 115);
	glVertex2i(248, 78);
	glVertex2i(218, 48);
	glVertex2i(182, 85);
	glEnd();

	//mtn-5
	glColor3ub(38, 172, 2);
	glBegin(GL_POLYGON);
	glVertex2i(188, 136);
	glVertex2i(306, 136);
	glVertex2i(344, 101);
	glVertex2i(284, 43);
	glEnd();
	glPopMatrix();
}
void skySC_2() {
	glColor3ub(162, 222, 224);
	drawRectangle(0, 136, 500, 136);
}
void boatSC_2() {
	//boat body
	glColor3ub(193, 104, 19);
	drawRectangle(0, 500, 500, 272);

	//boat lines
	//1
	glColor3ub(219, 121, 0);
	drawUnevenTriangle(427, 500, 500, 500, 500, 427);
	//2
	glColor3ub(116, 64, 0);
	drawQuad(346, 500, 427, 500, 500, 427, 500, 346);
	//3
	glColor3ub(219, 121, 0);
	drawQuad(261, 500, 346, 500, 500, 347, 500, 264);
	//4
	glColor3ub(116, 64, 0);
	glBegin(GL_POLYGON);
	glVertex2i(190, 500);
	glVertex2i(262, 500);
	glVertex2i(500, 264);
	glVertex2i(500, 230);
	glVertex2i(459, 230);
	glEnd();
	//5
	glColor3ub(219, 121, 0);
	drawQuad(113, 500, 190, 500, 459, 230, 383, 230);
	//6
	glColor3ub(116, 64, 0);
	drawQuad(43, 500, 112, 500, 381, 230, 310, 230);
	//7
	glColor3ub(219, 121, 0);
	glBegin(GL_POLYGON);
	glVertex2i(0, 469);
	glVertex2i(0, 500);
	glVertex2i(47, 500);
	glVertex2i(311, 230);
	glVertex2i(238, 230);
	glEnd();
	//8
	glColor3ub(116, 64, 0);
	drawQuad(0, 420, 0, 472, 238, 230, 191, 230);
	//9
	glColor3ub(219, 121, 0);
	drawQuad(0, 350, 0, 420, 189, 230, 115, 230);
	//10
	glColor3ub(116, 64, 0);
	drawQuad(0, 278, 0, 350, 115, 230, 49, 230);
	//11
	glColor3ub(219, 121, 0);
	drawUnevenTriangle(0, 275, 49, 230, 0, 230);

	//boatFence
	glColor3ub(193, 104, 19);
	drawRectangle(0, 200, 500, 10);
	drawRectangle(33, 230, 5, 30);
	drawRectangle(133, 230, 5, 30);
	drawRectangle(233, 230, 5, 30);
	drawRectangle(333, 230, 5, 30);
	drawRectangle(433, 230, 5, 30);

}
void chengHoSC_2() {

	/**********drawing HANG LI PO***********/
	glPushMatrix();
	glTranslatef(cHoMoveSC_2, 0, 0);
	//left hand 
	glColor3ub(236, 178, 99);
	drawRectangle(142, 402, 89, 43);
	//the face 
	glColor3ub(236, 178, 99);
	drawRectangle(89, 338, 52, 52);
	drawCircle(115, 330, 26);
	glColor3ub(0, 0, 0);
	drawCircle(103, 310, 5);
	drawCircle(132, 310, 5);
	glColor3ub(191, 144, 80);
	drawEllipse(118, 323, 7, 10, 100);
	glColor3ub(247, 65, 60);
	drawEllipse(115, 340, 11, 7, 100);
	//ze B O D Y
	glColor3ub(168, 255, 0);
	drawRectangle(68, 483, 96, 125);
	//right hand
	glColor3ub(236, 178, 99);
	drawRectangle(81, 475, 43, 107);
	//ze LEGZ
	glColor3ub(168, 169, 0);
	drawRectangle(68, 500, 96, 18);
	//above head
	glBegin(GL_POLYGON);
	glColor3ub(0, 0, 0);
	glVertex2i(90, 300);
	glVertex2i(141,300);
	glVertex2i(141, 286);
	glVertex2i(67, 286);
	glVertex2i(67, 332);
	glVertex2i(79, 332);
	glEnd();
	glPopMatrix();
}
void liPoSC_2() {

	/*********DRAWING PRINCESS LIPO**********/
	glPushMatrix();
	glTranslatef(lPMoveSC_2, 0, 0);
	//face
	glColor3ub(232, 197, 150);
	drawRectangle(89 + 249, 338, 52, 52);
	drawCircle(115+249, 330, 26);
	//face->eyes
	glColor3ub(0, 0, 0);
	drawCircle(103 + 249, 310, 5);
	drawCircle(132 + 249, 310, 5);
	//face->nose
	glColor3ub(191, 144, 80);
	drawEllipse(118 + 249, 323, 7, 10, 100);
	glColor3ub(247, 65, 60);
	drawEllipse(115 + 249, 340, 11, 7, 100);
	//ze B O D Y
	glColor3ub(230, 25, 163);
	drawRectangle(68 + 249, 483, 96, 125);
	//legs
	glColor3ub(109, 12, 77);
	drawRectangle(68+249, 500, 96, 18);
	glPopMatrix();
}

//SC_3
void waterSC_3() {
	glColor3ub(44, 200, 234);
	drawRectangle(0, 500, 500, 500);

	glPushMatrix();
	glTranslatef(0, waterLineSC_3, 0);
	//water line-1
	glColor3ub(0, 0, 0);
	drawRectangle(18, 52, 3, 37);
	//water line-2
	glColor3ub(0, 0, 0);
	drawRectangle(128, 107, 3, 37);
	//water line-3
	glColor3ub(0, 0, 0);
	drawRectangle(124, 229, 3, 37);
	//water line-4
	glColor3ub(0, 0, 0);
	drawRectangle(97, 444, 3, 37);
	//water line-5
	glColor3ub(0, 0, 0);
	drawRectangle(305, 90, 3, 37);
	//water line-6
	glColor3ub(0, 0, 0);
	drawRectangle(254, 315, 3, 37);
	//water line-7
	glColor3ub(0, 0, 0);
	drawRectangle(440, 104, 3, 37);
	//water line-8
	glColor3ub(0, 0, 0);
	drawRectangle(435, 389, 3, 37);
	glPopMatrix();
}
void boatGood() {
	glColor3ub(193, 104, 19);
	drawRectangle(202, 169, 60, 108);
	glColor3ub(55, 30, 5);
	drawTriangle(202, 61, 262, 61, 232, 8);
	glColor3ub(84, 45, 8);
	drawRectangle(208, 164, 6, 98);
	drawRectangle(228, 133, 6, 47);
	drawRectangle(250, 164, 6, 98);
}
void boatBad1() {
	glPushMatrix();
	glTranslatef(0, boatBad1_MoveSC_3, 0);
	glColor3ub(193, 104, 19);
	drawRectangle(40, 343, 42, 83);
	glColor3ub(55, 30, 5);
	drawTriangle(30, 260, 94, 260, 62, 200);
	glColor3ub(208, 132, 59);
	drawCircle(61, 241, 10);
	drawRectangle(54, 338, 14, 75);
	glPopMatrix();
}
void boatBad2() {
	glPushMatrix();
	glTranslatef(0, boatBad2_MoveSC_3, 0);
	glColor3ub(193, 104, 19);
	drawRectangle(321, 416, 46, 98);
	glColor3ub(55, 30, 5);
	drawTriangle(295, 318, 395, 318, 345, 271);
	glColor3ub(208, 132, 59);
	drawCircle(345, 299, 10);
	drawRectangle(335, 409, 18, 85);
	//9/11 was an inside job
	glPopMatrix();
}

//SC_4
void waterSC_4() {
	glColor3ub(44, 200, 234);
	drawRectangle(0, 500, 500, 500);

	glPushMatrix();
	glTranslatef(waterLineSC_4, 0, 0);
	//waterLineSC_4
	glColor3ub(0, 0, 0);
	drawRectangle(82, 83, 51, 3);
	drawRectangle(349, 81, 51, 3);
	drawRectangle(82, 83, 51, 3);
	drawRectangle(421, 30, 51, 3);
	drawRectangle(21, 243, 51, 3);
	drawRectangle(80, 268, 51, 3);
	drawRectangle(113, 273, 51, 3);
	drawRectangle(215, 251, 51, 3);
	drawRectangle(327, 236, 51, 3);
	drawRectangle(429, 272, 51, 3);
	drawRectangle(455, 216, 51, 3);
	glPopMatrix();
}
void boatBadSC_4() {
	glColor3ub(127, 69, 12);
	drawQuad(0, 212, 372, 214, 466, 118, 0, 118);
	glColor3ub(127, 92, 62);
	drawQuad(0, 141, 443, 141, 466, 118, 0, 118);
	//layar
	glColor3ub(209, 219, 172);
	drawQuad(0, 62, 430, 62, 345, 0, 0, 0);
	//tiang thing
	glColor3ub(127, 69, 12);
	drawRectangle(163, 118, 5, 118);
	drawRectangle(0, 40, 341, 5);
	drawRectangle(0, 14, 341, 5);
}
void boatGoodSC_4() {
	glPushMatrix();
	glTranslatef(boatGoodMoveSC_4, 0, 0);
	glColor3ub(193, 104, 19);
	drawQuad(0, 500, 300, 500, 500, 323, 0, 323);
	glColor3ub(103, 56, 10);
	drawQuad(0, 451, 355, 451, 448, 369, 0, 369);
	glColor3ub(232, 130, 48);
	drawQuad(0, 323, 471, 323, 471, 292, 0, 292);
	glColor3ub(103, 56, 10);
	drawRectangle(18, 323, 30, 31);
	drawRectangle(118, 323, 30, 31);
	drawRectangle(218, 323, 30, 31);
	drawRectangle(318, 323, 30, 31);
	drawRectangle(418, 323, 30, 31);
	glPopMatrix();
}
void badGuySC_4() {
	//face
	glColor3ub(255, 181, 114);
	drawCircle(215, 98, 13);
	//eyes-left
	glColor3ub(255, 255, 255);
	drawCircle(207, 96, 3);
	glColor3ub(0, 0, 0);
	drawRectangle(207, 97, 2, 2);
	//eyes-right
	glColor3ub(255, 255, 255);
	drawCircle(207+14, 96, 3);
	glColor3ub(0, 0, 0);
	drawRectangle(207+14, 97, 2, 2);
	//ze mouth
	glColor3ub(223, 68, 95);
	drawEllipse(214, 104, 6, 4, 100); 
	//ze hat
	glColor3ub(160, 163, 52);
	drawTriangle(197, 89, 231, 89, 214, 74);
	//ze body
	glColor3ub(194, 143, 52);
	drawRectangle(193, 118, 38, 9);
	
}

//SC_5
void seaWaterSC_5() {
	glColor3ub(44, 200, 234);
	drawRectangle(0, 500, 500, 500);
}
void boatGoodSC_5() {
	//boat body
	glColor3ub(127, 69, 12);
	drawRectangle(0, 500, 500, 223);
	//the stripe
	glColor3ub(172, 62, 27);
	drawQuad(58, 500, 245, 500, 468, 277, 277, 277);
	drawQuad(0, 361, 0, 449, 172, 277, 83, 277);
	drawUnevenTriangle(401, 500, 500, 500, 500, 400);
	//fence
	glColor3ub(201, 112, 25);
	drawRectangle(0, 218, 500, 10);
	glColor3ub(162, 113, 64);
	drawRectangle(42, 277, 10, 59);
	drawRectangle(142, 277, 10, 59);
	drawRectangle(242, 277, 10, 59);
	drawRectangle(342, 277, 10, 59);
	drawRectangle(442, 277, 10, 59);
}
void boatBad1SC_5() {
	glPushMatrix();
	glTranslatef(boatBad1MoveSC_5, 0, 0);
	//boat body
	glColor3ub(127, 69, 12);
	drawQuad(143, 102, 321, 102, 346, 77, 120, 77);
	glColor3ub(179, 114, 49);
	drawQuad(137, 95, 329, 95, 336, 86, 129, 86);
	//the layar
	glColor3ub(238, 207, 176);
	drawTriangle(167, 59, 313, 59, 240, 8);
	//the tiang 
	glColor3ub(179, 114, 49);
	drawRectangle(240, 77, 5, 54);
	glPopMatrix();
}
void boatBad2SC_5() {
	glPushMatrix();
	glTranslatef(boatBad2MoveSC_5, 0, 0);
	//the body
	glColor3ub(208, 88, 11);
	drawQuad(318, 175, 445, 175, 466, 151, 300, 151);
	glColor3ub(190, 11, 61);
	drawQuad(313, 169, 449, 169, 458, 158, 305, 158);
	//the sail
	glColor3ub(238, 207, 176);
	drawTriangle(316, 139, 443, 139, 380, 110);
	//the tiang
	glColor3ub(179, 114, 49);
	drawRectangle(381,151, 5, 12);
	glPopMatrix();
}
void liPoSC_5() {
	glPushMatrix();
	glTranslatef(princessMoveSC_5, 0, 0);
	//the body
	glColor3ub(230, 25, 163);
	drawTriangle(58, 425, 144, 425, 101, 337);
	//the face
	glColor3ub(232, 197, 150);
	drawCircle(102, 325, 21);
	//the eyes
	glColor3ub(255, 255, 255);
	drawCircle(116, 324, 5);
	glColor3ub(0, 0, 0);
	drawRectangle(116, 325, 3, 3);
	//the hair 
	glColor3ub(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2d(82, 328);
	glVertex2i(120, 312);
	glVertex2i(104, 296);
	glVertex2i(85, 295);
	glVertex2i(64, 328);
	glVertex2i(81, 351);
	glEnd();
	//the mouth 
	glColor3ub(241, 64, 72);
	drawTriangle(108, 335, 112, 341, 118, 335);
	//the hand
	glColor3ub(198, 123, 173);
	drawRectangle(94, 409, 12, 42);
	//the leg
	drawRectangle(72, 442, 17, 17);
	drawRectangle(118, 442, 17, 17);
	glPopMatrix();
}
void chengHoSC_5() {
	glPushMatrix();
	glTranslatef(chengHoMoveSC_5, 0, 0);
	//the body
	glColor3ub(168, 255, 0);
	drawRectangle(200, 416, 62, 62);
	//the legs 
	glColor3ub(98, 135, 28);
	drawRectangle(200, 467, 23, 51);
	drawRectangle(238, 467, 23, 51);
	//left hand 
	glColor3ub(98, 135, 28);
	drawQuad(168, 394, 200, 379, 200, 360, 160, 377);
	//right hand -6 points
	glColor3ub(98, 135, 28);
	glBegin(GL_POLYGON);
	glVertex2i(263, 383);
	glVertex2i(276, 391);
	glVertex2i(311, 355);
	glVertex2i(294, 346);
	glVertex2i(274, 366);
	glVertex2i(262, 360);
	glEnd();
	//the head
	glColor3ub(236, 178, 99);
	drawCircle(234, 322, 29);
	//the eyes
	glColor3ub(255, 255, 255);
	drawCircle(246, 327, 6);
	glColor3ub(0, 0, 0);
	drawRectangle(247, 329, 3, 3);
	//the mouth 
	glColor3ub(241, 64, 72);
	drawTriangle(238, 345, 250, 349, 255, 339);
	//the hair - 9 points
	glColor3ub(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2i(209 + 10, 325 - 20);
	glVertex2i(252 + 10, 316 - 20);
	glVertex2i(231 + 10, 306 - 20);
	glVertex2i(222 + 10, 309 - 20);
	glVertex2i(206 + 10, 304 - 20);
	glVertex2i(191 + 10, 321 - 20);
	glVertex2i(201 + 10, 325 - 20);
	glVertex2i(206 + 10, 307 - 20);
	glVertex2i(215 + 10, 314 - 20);
	glEnd();
	glPopMatrix();
}
void badGuySC_5() {
	//drawface
	glColor3ub(255, 181, 114);
	drawCircle(458, 324, 18);
	//the eye SHEEEEESH
	glColor3ub(255, 255, 255);
	drawCircle(454, 319, 6);
	glColor3ub(0, 0, 0);
	drawRectangle(452, 321, 3, 3);
	//the mouth
	glColor3ub(224, 47, 59);
	drawTriangle(444, 335, 454, 332, 441, 326);
	//the hat
	glColor3ub(160, 163, 52);
	drawTriangle(437, 310, 478, 310, 457, 294);
	//the right hand
	glColor3ub(235, 198, 130);
	drawQuad(404, 361, 450, 354, 450, 348, 405, 340);
	//the body
	glColor3ub(194, 143, 52);
	drawRectangle(433, 393, 43, 53);
	//the legs
	glColor3ub(235, 198, 130);
	drawRectangle(434, 430, 15, 37);
	drawRectangle(463-3, 430, 15, 37);
	//the hand-left 
	glColor3ub(235, 198, 130);
	drawQuad(410, 366, 452, 356, 452, 351, 410, 346);
	//the sword->the handle
	glColor3ub(0, 0, 0);
	drawQuad(399, 341, 410, 351, 410, 346, 401, 338);
	glColor3ub(236, 233, 38);
	drawQuad(393, 341, 395, 343, 404, 333, 404, 331);
	//the sword->the blade
	glColor3ub(134, 133, 112);
	glBegin(GL_POLYGON);
	glVertex2i(360, 302);
	glVertex2i(396, 338);
	glVertex2i(401,333);
	glVertex2i(365, 297);
	glVertex2i(360, 297);
	glEnd();
}

//SC_6
void seaWaterSC_6() {
	glColor3ub(44, 200, 234);
	drawRectangle(0, 500, 500, 402);
}
void skySC_6() {
	glColor3ub(162, 222, 224);
	drawRectangle(0, 99, 500, 100);
	//the cloud-1
	glPushMatrix();
	glTranslatef(cloudMoveSC_6, 0, 0);
	glColor3ub(255, 255, 255);
	drawCircle(117, 31, 17);
	drawCircle(144, 30, 15);
	drawCircle(165, 31, 13);
	drawCircle(164, 18, 15);
	drawCircle(187, 39, 12);
	//the cloud-2
	glColor3ub(255, 255, 255);
	drawCircle(364, 35, 17);
	drawCircle(379, 26, 12);
	drawCircle(396, 31, 18);
	drawCircle(417, 18, 13);
	drawCircle(415, 46, 17);
	drawCircle(441, 29, 18);
	glPopMatrix(); 
}
void boatSC_6() {
	//6points
	glColor3ub(127, 69, 12);
	glBegin(GL_POLYGON);
	glVertex2i(0, 500);
	glVertex2i(500, 500);
	glVertex2i(500, 310);
	glVertex2i(373, 88);
	glVertex2i(107, 88);
	glVertex2i(0, 310);
	glEnd();
	//1
	glColor3ub(172, 62, 27);
	drawQuad(22, 500, 252, 500, 254, 88, 164, 88);
	//2->same color
	drawQuad(500, 500, 500, 312, 375, 87, 311, 87);
	//the fences
	glColor3ub(201, 112, 25);
	drawQuad(0, 309, 108, 88, 105, 57, 0, 233);
	drawQuad(107, 88, 375, 88, 376, 57, 104, 57);
	drawQuad(500, 314, 500, 230, 376, 58, 375, 88);
	glColor3ub(56, 32, 7);
	drawRectangle(106, 88, 3, 30);
	drawRectangle(374, 88, 3, 30);
}
void lipoSC_6() {
	//face
	glColor3ub(232, 197, 150);
	drawCircle(160, 143, 37);
	//face->eyes->left
	glColor3ub(255, 255, 255);
	drawCircle(141, 135, 6);
	glColor3ub(0, 0, 0);
	drawRectangle(138, 137, 3, 3);
	//face->eyes->right
	glColor3ub(255, 255, 255);
	drawCircle(172, 135, (172 - 165));
	glColor3ub(0, 0, 0);
	drawRectangle(170, 137, 3, 3);
	//face->nose
	glColor3ub(209, 175, 129);
	drawTriangle(154, 152, 163, 150, 155, 143);
	//face->mouth 
	glColor3ub(214, 78, 92);
	drawEllipse(156 + 3, 165, 18, 5, 100);
	//body->neck->5 points
	glColor3ub(232, 197, 150);
	glBegin(GL_POLYGON);
	glVertex2i(148, 183);
	glVertex2i(155, 191);
	glVertex2i(164, 184);
	glVertex2i(161, 174);
	glVertex2i(149, 174);
	glEnd();
	//body->real body->8 points
	glColor3ub(230, 25, 163);
	glBegin(GL_POLYGON);
	glVertex2i(154, 191);
	glVertex2i(148, 183);
	glVertex2i(119, 190);
	glVertex2i(106, 236);
	glVertex2i(131, 247);
	glVertex2i(210, 236);
	glVertex2i(206, 194);
	glVertex2i(164, 184);
	glEnd();
	//hand->will be partially hidden
	glColor3ub(232, 197, 150);
	drawQuad(106, 238, 110, 267, 168, 243, 168, 234);
	//eye-bro
	glColor3ub(0, 0, 0);
	drawQuad(130, 127, 132, 129, 145, 123, 143, 121);
	//another eye-bro LOL
	drawQuad(165, 123, 168, 126, 183, 128, 180, 125);
	//hair->6 points
	glColor3ub(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2i(120, 113);
	glVertex2i(131, 118);
	glVertex2i(181, 118);
	glVertex2i(186, 114);
	glVertex2i(177, 101);
	glVertex2i(124, 101);
	glEnd();
	//another hair->left
	drawQuad(105, 151, 120, 169, 131, 118, 119, 112);
	//another hair->right 
	drawQuad(180, 119, 193, 165, 209, 144, 186, 114);
}
void chengHoSC_6() {
	//the head 
	glPushMatrix();
	glTranslatef(chengHoMoveSC_6, 0, 0);
	glColor3ub(236, 178, 99);
	drawCircle(237, 293, 238 - 122);
	//the eyes->left 
	glColor3ub(255, 255, 255);
	drawCircle(176, 302, 176 - 152);
	//the eye bro-left
	glColor3ub(0, 0, 0);
	drawRectangle(171, 304, 12, 12);
	//the eyes->right
	glColor3ub(255, 255, 255);
	drawCircle(304, 301, 304 - 279);
	//the eye bro->right 
	glColor3ub(0, 0, 0);
	drawRectangle(296, 305, 12, 12);
	//the nose bro
	glColor3ub(182, 140, 83);
	drawTriangle(223, 336, 259, 333, 231, 312);
	//the mouth bro
	glColor3ub(236, 32, 91);
	drawEllipse(240, 375, 60, 20, 100);
	//eye bro->left
	glColor3ub(0, 0, 0);
	drawQuad(137, 271, 141, 276, 156, 262, 157, 254);
	drawQuad(156, 261, 215, 284, 220, 273, 158, 253);
	//eye bro->right 
	glColor3ub(0, 0, 0);
	drawQuad(255, 285, 314, 262, 312, 254, 250, 274);
	drawQuad(312, 263, 330, 278, 333, 272, 312, 254);
	//the hair bro
	glColor3ub(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2i(128, 249 - 3);
	glVertex2i(345, 249 - 3);
	glVertex2i(348, 214 - 3);
	glVertex2i(311, 180 - 3);
	glVertex2i(158, 180 - 3);
	glVertex2i(124, 221 - 3);
	glEnd();
	//the NECK BRO 
	glColor3ub(236, 178, 99);
	glBegin(GL_POLYGON);
	glVertex2i(207, 390 + 5);
	glVertex2i(210, 418 + 5);
	glVertex2i(240, 456 + 5);
	glVertex2i(269, 417 + 5);
	glVertex2i(272, 387 + 5);
	glEnd();
	//the body SHEESH
	glColor3ub(168, 255, 0);
	glBegin(GL_POLYGON);
	glVertex2i(62, 500);
	glVertex2i(428, 500);
	glVertex2i(426, 462);
	glVertex2i(269, 417);
	glVertex2i(240, 457);
	glVertex2i(209, 418);
	glVertex2i(54, 463);
	glEnd();
	glPopMatrix();
}

//SC_7
void boatSC_7() {
	//boat body
	glColor3ub(193, 104, 19);
	drawRectangle(0, 500, 500, 272);

	//boat lines
	//1
	glColor3ub(219, 121, 0);
	drawUnevenTriangle(427, 500, 500, 500, 500, 427);
	//2
	glColor3ub(116, 64, 0);
	drawQuad(346, 500, 427, 500, 500, 427, 500, 346);
	//3
	glColor3ub(219, 121, 0);
	drawQuad(261, 500, 346, 500, 500, 347, 500, 264);
	//4
	glColor3ub(116, 64, 0);
	glBegin(GL_POLYGON);
	glVertex2i(190, 500);
	glVertex2i(262, 500);
	glVertex2i(500, 264);
	glVertex2i(500, 230);
	glVertex2i(459, 230);
	glEnd();
	//5
	glColor3ub(219, 121, 0);
	drawQuad(113, 500, 190, 500, 459, 230, 383, 230);
	//6
	glColor3ub(116, 64, 0);
	drawQuad(43, 500, 112, 500, 381, 230, 310, 230);
	//7
	glColor3ub(219, 121, 0);
	glBegin(GL_POLYGON);
	glVertex2i(0, 469);
	glVertex2i(0, 500);
	glVertex2i(47, 500);
	glVertex2i(311, 230);
	glVertex2i(238, 230);
	glEnd();
	//8
	glColor3ub(116, 64, 0);
	drawQuad(0, 420, 0, 472, 238, 230, 191, 230);
	//9
	glColor3ub(219, 121, 0);
	drawQuad(0, 350, 0, 420, 189, 230, 115, 230);
	//10
	glColor3ub(116, 64, 0);
	drawQuad(0, 278, 0, 350, 115, 230, 49, 230);
	//11
	glColor3ub(219, 121, 0);
	drawUnevenTriangle(0, 275, 49, 230, 0, 230);

	//boatFence
	glColor3ub(193, 104, 19);
	drawRectangle(0, 200, 500, 10);
	drawRectangle(33, 230, 5, 30);
	drawRectangle(133, 230, 5, 30);
	drawRectangle(233, 230, 5, 30);
	drawRectangle(333, 230, 5, 30);
	drawRectangle(433, 230, 5, 30);
}
void waterSC_7() {
	glColor3ub(44, 200, 234);
	glBegin(GL_POLYGON);
	glVertex2i(0, 500);
	glVertex2i(500, 500);
	glVertex2i(500, 146);
	glVertex2i(0, 146);
	glEnd();


	//waterLine 
	//line-1
	glPushMatrix();
	glTranslatef(waterLineSC_2, 0, 0);
	glColor3ub(0, 0, 0);
	drawRectangle(29, 180, 30, 2);
	drawRectangle(32, 161, 33, 2);
	drawRectangle(114, 163, 43, 2);
	drawRectangle(127, 180, 26, 2);
	drawRectangle(204, 169, 31, 2);
	drawRectangle(258, 181, 30, 2);
	drawRectangle(334, 157, 30, 2);
	drawRectangle(374, 172, 30, 2);
	drawRectangle(432, 157, 30, 2);
	glPopMatrix();

}
void skySC_7() {
	glColor3ub(162, 222, 224);
	drawRectangle(0, 156, 500, 156);
}
void chengHoSC_7() {
	glPushMatrix();
	glTranslatef(chengHoMoveC_x_7, chengHoMoveC_y_7, 0);
	//the face 
	glColor3ub(236, 178, 99);
	drawCircle(82, 310, 82 - 53);
	//the eye
	glColor3ub(255, 255, 255);
	drawCircle(94, 297, 94 - 85);
	glColor3ub(0, 0, 0);
	drawRectangle(92, 300, 3, 3);
	//the nose 
	glColor3ub(182, 140, 83);
	drawTriangle(98, 315, 104, 315, 104, 309);
	//the mouth 
	glColor3ub(236, 32, 91);
	drawEllipse(90, 326, 11, 4, 100);
	//the hair GOTTA GAINZ THE DRIPZ
	glColor3ub(0, 0, 0);
	drawQuad(60, 297, 97, 285, 80, 275, 57, 279);
	drawQuad(47, 324, 60, 299, 56, 279, 40, 306);
	//the neck
	glColor3ub(236, 178, 99);
	glBegin(GL_POLYGON);
	glVertex2i(75, 348);
	glVertex2i(85, 354);
	glVertex2i(89, 346);
	glVertex2i(90, 336);
	glVertex2i(73, 336);
	glEnd();
	//the hand->right 
	glColor3ub(98, 135, 28);
	drawQuad(30, 382, 43, 382, 39, 337, 23, 340);
	drawQuad(43, 381, 93, 377, 92, 360, 43, 366);
	//the hand-left 
	glColor3ub(98, 135, 28);
	drawQuad(126, 367, 168, 336, 160, 326, 119, 353);
	//the legz->right 
	glColor3ub(98, 135, 28);
	drawQuad(94, 418, 75, 435, 103, 428, 110, 409);
	drawQuad(76, 435, 137, 469, 148, 454, 103, 428);
	//the legz->left
	glColor3ub(98, 135, 28);
	drawQuad(124, 400, 219, 404, 219, 375, 136, 391);
	//the B O D Y
	glColor3ub(168, 255, 0);
	glBegin(GL_POLYGON);
	glVertex2i(96, 418);
	glVertex2i(136, 391);
	glVertex2i(110, 334);
	glVertex2i(89, 345);
	glVertex2i(86, 354);
	glVertex2i(74, 348);
	glVertex2i(62, 360);
	glEnd();
	glPopMatrix();
}
void badGuySC_7() {
	glPushMatrix();
	glTranslatef(badGuyMoveSC_7, 0, 0);
	//the head
	glColor3ub(255, 181, 114);
	drawCircle(363, 310, 363 - 332);
	//the eye
	glColor3ub(255, 255, 255);
	drawCircle(346, 304, 346 - 339);
	glColor3ub(0, 0, 0);
	drawRectangle(343, 307, 3, 3);
	//the mouth
	glColor3ub(223, 68, 95);
	drawTriangle(336, 323, 345, 333, 359, 332);
	//the hat 
	glColor3ub(160, 163, 52);
	drawTriangle(322, 292, 400, 291, 362, 264);
	//the neck
	glColor3ub(255, 181, 114);
	glBegin(GL_POLYGON);
	glVertex2i(353, 336);
	glVertex2i(352, 345);
	glVertex2i(360, 349);
	glVertex2i(371, 342);
	glVertex2i(368, 336);
	glEnd();
	//the hand->right 
	glColor3ub(235, 198, 130);
	drawQuad(310, 395, 337, 381, 337, 355, 303, 379);
	//the body
	glColor3ub(194, 143, 52);
	glBegin(GL_POLYGON);
	glVertex2i(338, 413);
	glVertex2i(381, 412);
	glVertex2i(380, 346);
	glVertex2i(370, 342);
	glVertex2i(361, 349);
	glVertex2i(352, 345);
	glVertex2i(337, 352);
	glEnd();
	//the hand->left hand 
	glColor3ub(235, 198, 130);
	drawQuad(375, 373, 412, 353, 410, 336, 375, 360);
	//the sword
	glColor3ub(0, 0, 0);
	drawQuad(412, 346, 422, 340, 419, 336, 411, 342);
	glColor3ub(236, 233, 38);
	drawQuad(427, 344, 429, 343, 417, 328, 414, 330);
	//the sword->blade
	glColor3ub(134, 133, 112);
	glBegin(GL_POLYGON);
	glVertex2i(426, 340);
	glVertex2i(460, 299);
	glVertex2i(462, 290);
	glVertex2i(451, 294);
	glVertex2i(420, 331);
	glEnd();
	//the legs->right
	glColor3ub(235, 198, 130);
	drawQuad(317, 427, 337, 429, 360, 414, 338, 413);
	drawQuad(338, 461, 354, 457, 337, 429, 317, 427);
	//the legs->left
	glColor3ub(235, 198, 130);
	drawQuad(393, 456, 412, 449, 381, 413, 352, 414);
	glPopMatrix();
}

//SC_8
void redSCreencSC_8() {
	glColor3ub(230, 18, 0);
	drawRectangle(0, 500, 500, 500);
}

//SC_9
void skySC_9() {
	glColor3ub(162, 222, 224);
	drawRectangle(0, 156, 500, 156);
}
void waterSC_9() {
	glColor3ub(44, 200, 234);
	glBegin(GL_POLYGON);
	glVertex2i(0, 500);
	glVertex2i(500, 500);
	glVertex2i(500, 146);
	glVertex2i(0, 146);
	glEnd();
	//waterLine 
	glPushMatrix();
	glTranslatef(waterLineSC_2, 0, 0);
	glColor3ub(0, 0, 0);
	drawRectangle(29, 180, 30, 2);
	drawRectangle(32, 161, 33, 2);
	drawRectangle(114, 163, 43, 2);
	drawRectangle(127, 180, 26, 2);
	drawRectangle(204, 169, 31, 2);
	drawRectangle(258, 181, 30, 2);
	drawRectangle(334, 157, 30, 2);
	drawRectangle(374, 172, 30, 2);
	drawRectangle(432, 157, 30, 2);
	glPopMatrix();

}
void boatSC_9() {
	//boat body
	glColor3ub(193, 104, 19);
	drawRectangle(0, 500, 500, 272);

	//boat lines
	//1
	glColor3ub(219, 121, 0);
	drawUnevenTriangle(427, 500, 500, 500, 500, 427);
	//2
	glColor3ub(116, 64, 0);
	drawQuad(346, 500, 427, 500, 500, 427, 500, 346);
	//3
	glColor3ub(219, 121, 0);
	drawQuad(261, 500, 346, 500, 500, 347, 500, 264);
	//4
	glColor3ub(116, 64, 0);
	glBegin(GL_POLYGON);
	glVertex2i(190, 500);
	glVertex2i(262, 500);
	glVertex2i(500, 264);
	glVertex2i(500, 230);
	glVertex2i(459, 230);
	glEnd();
	//5
	glColor3ub(219, 121, 0);
	drawQuad(113, 500, 190, 500, 459, 230, 383, 230);
	//6
	glColor3ub(116, 64, 0);
	drawQuad(43, 500, 112, 500, 381, 230, 310, 230);
	//7
	glColor3ub(219, 121, 0);
	glBegin(GL_POLYGON);
	glVertex2i(0, 469);
	glVertex2i(0, 500);
	glVertex2i(47, 500);
	glVertex2i(311, 230);
	glVertex2i(238, 230);
	glEnd();
	//8
	glColor3ub(116, 64, 0);
	drawQuad(0, 420, 0, 472, 238, 230, 191, 230);
	//9
	glColor3ub(219, 121, 0);
	drawQuad(0, 350, 0, 420, 189, 230, 115, 230);
	//10
	glColor3ub(116, 64, 0);
	drawQuad(0, 278, 0, 350, 115, 230, 49, 230);
	//11
	glColor3ub(219, 121, 0);
	drawUnevenTriangle(0, 275, 49, 230, 0, 230);

	//boatFence
	glColor3ub(193, 104, 19);
	drawRectangle(0, 200, 500, 10);
	drawRectangle(33, 230, 5, 30);
	drawRectangle(133, 230, 5, 30);
	drawRectangle(233, 230, 5, 30);
	drawRectangle(333, 230, 5, 30);
	drawRectangle(433, 230, 5, 30);
}
void liPoSC_9() {
	glPushMatrix();
	glTranslatef(lipoMoveSC_9, 0, 0);
	//hand->left
	glColor3ub(198, 123, 173);
	drawQuad(59, 399, 116, 398, 116, 387, 61, 388);
	//the body
	glColor3ub(230, 25, 163);
	drawTriangle(2, 452, 97, 452, 61, 363);
	//the face
	glColor3ub(232, 197, 150);
	drawCircle(61, 344, 61 - 35);
	//face->eye
	glColor3ub(255, 255, 255);
	drawCircle(73, 341, 73 - 69);
	glColor3ub(0, 0, 0);
	drawRectangle(73, 342, 3, 3);
	//the mouth 
	glColor3ub(241, 64, 72);
	drawEllipse(71, 356, 7, 3, 100);
	//the hair 
	glColor3ub(0, 0, 0);
	drawQuad(38, 336, 80, 328, 75, 310, 36, 321);
	drawTriangle(18, 355, 43, 374, 36, 325);
	//hand->right 
	glColor3ub(198, 123, 173);
	drawQuad(55, 445, 68, 445, 68, 392, 55, 392);
	//dem legss
	glColor3ub(198, 123, 173);
	drawQuad(37, 465, 48, 465, 48, 453, 37, 453);
	drawQuad(76, 465, 89, 465, 89, 453, 76, 453);
	glPopMatrix();
}
void chengHoSC_9() {
	//the body-> he do be dead tho RIP
	glColor3ub(168, 255, 0);
	glBegin(GL_POLYGON);
	glVertex2i(189, 467);
	glVertex2i(246, 462);
	glVertex2i(239, 414);
	glVertex2i(189, 412);
	glVertex2i(185, 437);
	glVertex2i(196, 446);
	glVertex2i(185, 456);
	glEnd();
	//hand->right 
	glColor3ub(98, 135, 28);
	drawQuad(199, 465, 221, 463, 228, 430, 216, 428);
	//hand->left
	glColor3ub(98, 135, 28);
	drawQuad(205, 413, 217, 413, 193, 376, 177, 384);
	//legz->right 
	glColor3ub(98, 135, 28);
	drawQuad(247, 462, 336, 451, 334, 433, 244, 443);
	//legz->left
	glColor3ub(98, 135, 28);
	drawQuad(242, 436, 279, 406, 279, 383, 239, 416);
	drawQuad(279, 406, 308, 429, 321, 412, 279, 383);
	//the neck
	glColor3ub(236, 178, 99);
	drawQuad(184, 456, 196, 445, 185, 437, 178, 439);
	//the head
	glColor3ub(236, 178, 99);
	drawCircle(154, 440, 154 - 130);
	//the eyes
	glColor3ub(0, 0, 0);
	drawRectangle(144, 455, 4, 11);
	drawRectangle(144, 435, 4, 11);
	//the mouth->he do be dead
	glColor3ub(0, 0, 0);
	drawRectangle(163, 448, 3, 13);
	//the hair 
	glColor3ub(0, 0, 0);
	drawQuad(126, 461, 135, 465, 135, 422, 123, 437);
	//blood
	glColor3ub(230, 18, 0);
	drawCircle(203, 424, 203 - 195);
}
void badGuySC_9() {
	glPushMatrix();
	glTranslatef(badGuyMoveSC_9, 0, 0);
	//the hand->right 
	glColor3ub(235, 198, 130);
	drawQuad(417, 389, 440, 417, 451, 406, 417, 373);
	//the body
	glColor3ub(194, 143, 52);
	glBegin(GL_POLYGON);
	glVertex2i(383, 413);
	glVertex2i(422, 413);
	glVertex2i(422, 369);
	glVertex2i(405, 363);
	glVertex2i(400, 368);
	glVertex2i(395, 365);
	glVertex2i(383, 368);
	glEnd();
	//the hand->left
	glColor3ub(235, 198, 130);
	drawQuad(361, 384, 402, 383, 402, 372, 361, 372);
	//the sword->handle
	glColor3ub(0, 0, 0);
	drawQuad(357, 381, 361, 381, 361, 376, 358, 376);
	glColor3ub(236, 233, 38);
	drawQuad(354, 386, 357, 386, 357, 372, 354, 372);
	//sword->the blade
	glColor3ub(134, 133, 112);
	drawQuad(305, 381, 354, 381, 354, 376, 306, 376);
	//the legz
	glColor3ub(235, 198, 130);
	drawQuad(379, 455, 393, 455, 403, 413, 383, 413);
	drawQuad(415, 455, 432, 456, 422, 413, 404, 413);
	//the head
	glColor3ub(255, 181, 114);
	drawCircle(401, 336, 401 - 378);
	//the eye bro
	glColor3ub(0, 0, 0);
	drawQuad(382, 326, 383, 327, 394, 324, 393, 323);
	//the eye
	glColor3ub(255, 255, 255);
	drawCircle(391, 331, 391 - 386);
	glColor3ub(0, 0, 0);
	drawRectangle(389, 332, 3, 3);
	//the mouth 
	glColor3ub(223, 68, 95);
	drawEllipse(392, 347, 392 - 384, 347 - 344, 100);
	//the hat 
	glColor3ub(160, 163, 52);
	drawTriangle(373, 322, 427, 322, 400, 304);
	//the neck
	glColor3ub(255, 181, 114);
	glBegin(GL_POLYGON);
	glVertex2i(395, 365);
	glVertex2i(400, 368);
	glVertex2i(404, 363);
	glVertex2i(403, 358);
	glVertex2i(397, 358);
	glEnd();
	glPopMatrix();
}

//SC_10
void skySC_10() {
	glColor3ub(28, 212, 230);
	drawRectangle(0, 500, 500, 500);
}
void hangTuah() {
	//hair 
	glColor3ub(0, 0, 0);
	drawTriangle(145, 285, 170, 234, 151 + 3, 210);
	glBegin(GL_POLYGON);
	glVertex2i(170, 234);
	glVertex2i(252, 235);
	glVertex2i(286, 204);
	glVertex2i(196, 200);
	glVertex2i(152, 209);
	glEnd();
	drawTriangle(291, 269, 286, 204, 253, 234);
	//the face
	glColor3ub(233, 170, 92);
	glBegin(GL_POLYGON);
	glVertex2i(159, 356);
	glVertex2i(206, 411);
	glVertex2i(284, 342);
	glVertex2i(286, 267 - 3);
	glVertex2i(252, 235 - 3);
	glVertex2i(169, 235 - 3);
	glVertex2i(144, 286);
	glEnd();
	//the eye bro
	glColor3ub(0, 0, 0);
	drawQuad(157, 272, 160, 280, 185, 280, 182, 277);
	drawQuad(223, 278, 220, 275, 259, 270, 256, 267);
	//the eye
	glColor3ub(255, 255, 255);
	drawQuad(155, 279, 162, 294, 196, 299, 193, 286);
	drawQuad(215, 302, 257, 296, 260, 275, 217, 287);
	glColor3ub(0, 0, 0);
	drawQuad(170, 291, 186, 293, 190, 286, 166, 281);
	drawQuad(236, 292, 252, 290, 255, 278, 229, 284);
	//the nose bro
	glColor3ub(0, 0, 0);
	drawQuad(195, 328, 192, 325, 203, 288, 206, 291);
	drawQuad(195, 329, 205, 335, 208, 338, 198, 332);
	//the mouth 
	glColor3ub(238, 46, 49);
	drawQuad(183, 364, 244, 363, 233, 349, 176, 349);
	//the  neck
	glColor3ub(212, 155, 85);
	glBegin(GL_POLYGON);
	glVertex2i(195, 427);
	glVertex2i(288, 408);
	glVertex2i(281, 345 - 2);
	glVertex2i(206, 413 - 2);
	glVertex2i(202, 407 - 2);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2i(176, 462);
	glVertex2i(254, 472);
	glVertex2i(342, 438);
	glVertex2i(288, 408);
	glVertex2i(155, 440-5);
	glEnd();
	//the body
	glColor3ub(98, 149, 84);
	glBegin(GL_POLYGON);
	glVertex2i(80, 500);
	glVertex2i(426, 500);
	glVertex2i(422, 461);
	glVertex2i(343, 437);
	glVertex2i(253, 473);
	glVertex2i(176, 462);
	glVertex2i(156 + 3, 440 - 3);
	glVertex2i(80, 473);
	glEnd();
}

//to be continue
void blackscreen() {
	glColor3ub(0, 0, 0);
	drawRectangle(0, 500, 500, 500);
}

//timer function
void timer(int) {
	count++;
	glutPostRedisplay();
	glutTimerFunc(1000 / 60, timer, 0);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	if (count > 0 && count < 720) { //SC_1
		sky();
		seaWater();
		boat();
		cloudSC_1 -= 0.15;
		waterLineSC_1 += 0.2;
		if (count > 0 && count < 90)
			boatMoveSC_1 += 0.3;
		else if (count > 90 && count < 180)
			boatMoveSC_1 -= 0.3;
		else if (count > 180 && count < 270)
			boatMoveSC_1 += 0.3;
		else if (count > 270 && count < 360)
			boatMoveSC_1 -= 0.3;
		else if (count > 360 && count < 450)
			boatMoveSC_1 += 0.3;
		else if (count > 450 && count < 540)
			boatMoveSC_1 -= 0.3;
		else if (count > 540 && count < 630)
			boatMoveSC_1 += 0.3;
		else if (count > 630 && count < 720)
			boatMoveSC_1 -= 0.3;

		//display text
		if (count > 120 && count < 420) {
			glColor3ub(0, 0, 0);
			drawText("SEKUMPULAN PEMUDA BERBUDAYA PRESENTS", 72, 80);
		}
		else if (count > 420 && 720) {
			glColor3ub(0, 0, 0);
			drawTextBig("SATRIA", 230-40, (500 / 5));
		}
	}
	else if (count > 720 && count < 3060) {//SC_2
		waterSC_2();
		skySC_2();
		mountainsSC_2();
		boatSC_2();
		chengHoSC_2();
		liPoSC_2();
		//animation stuff
		waterLineSC_2 -= 0.2;
		mtnSC_2 -= 0.06;
		if (cHoMoveSC_2 < 50) {
			cHoMoveSC_2 += 0.5;
		}
		if (count > 1260 && count < 1440 && lPMoveSC_2 < 100) {
			lPMoveSC_2 += 0.3;
		}

		//textdisplay
		if (count > 780 && count < 900) {
			glColor3ub(0, 0, 0);
			drawText("O ME PRINCESS LIPO WHAT ARE DOING HERE ON THE DECK?", 29, 266);
		}
		else if (count > 960 && count < 1080) {
			glColor3ub(0, 0, 0);
			drawText("O MIGHTY ADMIRAL CHENG HO, I AM DOING A CONFUSE", 29, 280);
		}
		else if (count > 1080 && count < 1200) {
			glColor3ub(0, 0, 0);
			drawText("FOR WHAT SHOULD I MARRY SULTAN MANSUR SYAH ", 29, 280);
		}
		else if (count > 1440 && count < 1620) {
			glColor3ub(0, 0, 0);
			drawText("I DON'T EVEN KNOW HIM, FATHER IS BEING CRUEL TO ME ", 29, 280);
		}
		else if (count > 1740 && count < 1920) {
			glColor3ub(0, 0, 0);
			drawText("PARDON ME MY PRINCESS, BUT SULTAN MANSUR SYAH IS A GOOD GUY", 29, 280);
		}
		else if (count > 2040 && count < 2280) {
			glColor3ub(0, 0, 0);
			drawText("HE IS TALL AND HENSEM, HE REALLY SUITS YOU ME PRINCESS", 29, 280);
		}
		else if (count > 2400 & count < 2640) {
			glColor3ub(0, 0, 0);
			drawText("I MEAN, HE OWNS THE GREAT MALACAN EMPIRE", 29, 250);
		}
		else if (count > 2760 && count < 3000) {
			glColor3ub(0, 0, 0);
			drawText("WHAT COULD BE LESS PERFECT THAN  HIM", 0, 250);
		}
	}
	else if (count >  3120 && count < 3900) { //SC_3
		//render scene
		waterSC_3();
		boatGood();
		boatBad1();
		boatBad2();
		//animation stuffs
		waterLineSC_3 += 0.4;
		if (boatBad1_MoveSC_3 > -300) {
			boatBad1_MoveSC_3 -= 0.1;
		}
		if (boatBad2_MoveSC_3 > -300) {
			boatBad2_MoveSC_3 -= 0.2;
		}
		//display texts 
		if (count > 3270 && count < 3570) {
			glColor3ub(0, 0, 0);
			drawText("WHILE ADMIRAL CHENG HO AND PRINCESS LIPO WERE TALKING...", 34, 459);
		}
		else if (count > 3600 && count < 3900) {
			glColor3ub(0, 0, 0);
			drawText("TWO SUS BOATS APPROACHED THEIR BOAT", 34, 459);
		}
		else if (count > 3960 && count < 4200) {
			glColor3ub(0, 0, 0);
			drawText("BUT WHO ARE THESE BOATS", 34, 459);
		}

	}
	else if (count > 3900 && count < 5580) {
		//render scenery
		waterSC_4();
		boatBadSC_4();
		badGuySC_4();
		boatGoodSC_4();

		//animation stuff
		if (count > 3900 && count < 5580) {
			waterLineSC_4 -= 0.1;
		}
		if (count > 3900 && count < 4200) {
			boatGoodMoveSC_4 -= 0.3;
		}

		//text diplay
		if (count > 4080 && count < 4380) {
			glColor3ub(0, 0, 0);
			drawText("HALT!!!!!!!!", 229, 68);
		}
		else if (count > 4500 && count < 4740) {
			glColor3ub(0, 0, 0);
			drawText("WHOMST'VE ASK US TO STOP??!", 75, 276);
		}
		else if (count > 4860 && count < 5100) {
			glColor3ub(0, 0, 0);
			drawText("STOP THE BOAT NOW OR WE ATTACK!", 229, 68);
		}
		else if (count > 5220 && count < 5520) {
			glColor3ub(0, 0, 0);
			drawText("WE WILL ATTACK YOU FOR WE WILL KIDNAP THE PRINCESS!", 86, 68);
		}
	}
	else if (count > 5640 && count < 7260) {//SC_5
		//on screen stuff
		seaWaterSC_5();
		boatGoodSC_5();
		boatBad1SC_5();
		boatBad2SC_5();
		liPoSC_5();
		chengHoSC_5();
		badGuySC_5();

		//animation stuff
		if (count > 5640 && count < 7000) {
			boatBad1MoveSC_5 -= 0.05;
			boatBad2MoveSC_5 -= 0.05;
		}
		if (count > 6360 && count < 6480) {
			princessMoveSC_5 -= 0.2;
		}
		if (count > 6720 && count < 6840) {
			chengHoMoveSC_5 -= 0.1;
		}

		//display text
		if (count > 5760 && count < 6000) {
			glColor3ub(0, 0, 0);
			drawText("WHO ARE YOU AND WHY HAVE YOU COME HERE", 113, 333-100);
		}
		else if (count > 6060 && count < 6360) {
			glColor3ub(0, 0, 0);
			drawText("I WAS TOLD TO KIDNAP THE PRINCESS", 396-170, 332-100);
		}
		else if (count > 6420 && count < 6660) {
			glColor3ub(0, 0, 0);
			drawText("WHAT??!!!", 32, 329-200);
		}
		else if (count > 6720 && count <6900) {
			glColor3ub(0, 0, 0);
			drawText("QUICK ME PRINCESS HIDE!", 172-50, 311);
		}
		else if (count > 6960 && count < 7200) {
			glColor3ub(0, 0, 0);
			drawText("WELL WELL, NO ONE IS GETTING NOWHERE!", 332-200, 290);
		}
}
	else if (count > 7320 && count < 8040) {//SC_6
		//renderScene
		seaWaterSC_6();
		skySC_6();
		boatSC_6();
		lipoSC_6();
		chengHoSC_6();
		//animation stuff
		if (count > 7320 && count < 8040) {
			cloudMoveSC_6 -= 0.1;
		}
		if (count > 7740 && count < 7920) {
			chengHoMoveSC_6 -= 0.3;
		}

		//display text
		if (count > 7380 && count < 7620) {
			glColor3ub(0, 0, 0);
			drawText("NO ONE IS KIDNAPPING ME PRINCESS LI PO", 83, 481);

		}
		else if (count > 7680 && count < 7980) {
			glColor3ub(0, 0, 0);
			drawText("STAND BACK ME PRINCESS. IT IS NO MORE MR NICE GUY TIME", 41, 481);
		}
}
	else if (count > 8100 && count < 9000) {
	//SC_7
	//draw stuff
	waterSC_7();
	skySC_7();
	boatSC_7();
	chengHoSC_7();
	badGuySC_7();
	//animation stuff
	if (count > 8100 && count <8160) {
		chengHoMoveC_x_7 = -220;
		chengHoMoveC_y_7 = -220;
	}
	else if (count > 8400 && count < 8520) {
		chengHoMoveC_x_7 += 1.83;
		chengHoMoveC_y_7 += 1.83;
	}
	else if (count > 8880 && count < 9000) {
		badGuyMoveSC_7 -= 1.41;
	}


	//display text
	if (count > 8160 && count < 8400) {
		glColor3ub(0, 0, 0);
		drawText("COME HERE! I HAVE NO TIME TO WASTE", 170, 473);
	}
	else if (count > 8520 && count < 8700) {
		glColor3ub(0, 0, 0);
		drawText("YOU ARE DEAD!!!!", 189, 472);
	}
	else if (count > 8760 && count < 8940) {
		glColor3ub(0, 0, 0);
		drawText("FOR USING BARE HAND TO A SWORD FIGHT", 189, 472);
	}
}
	else if (count > 9000 && count < 9300) {
	redSCreencSC_8();
	//scene 8 has no animation
	//display text
	if (count > 9060 && count < 9240) {
		glColor3ub(0, 0, 0);
		drawText("ADMIRAL CHENG!!!", 141, 458);
	}
}
	else if (count > 9360 && count < 11700) {
		//models
		waterSC_9();
		skySC_9();
		boatSC_9();
		liPoSC_9();
		chengHoSC_9();
		badGuySC_9();
		
		//animation
		if (count > 9360 && count < 9480) {
			lipoMoveSC_9 = -120;
		}
		else if (count > 9480 && count < 9600) {
			lipoMoveSC_9 += 1;
		}
		else if (count > 10920 && count < 11100) {
			badGuyMoveSC_9 -= 0.2;
		}

		//display text
		if (count > 9420 && count < 9600) {
			glColor3ub(0, 0, 0);
			drawText("ADMIRAL CHENGG!!!, NO NO NO!!!!", 69, 472);
		}
		else if (count > 9660 && count < 9840) {
			glColor3ub(0, 0, 0);
			drawText("GO PRINCESS, GO RUN SAVE YOURSELF", 124, 481);
		}
		else if (count > 9900 && count < 10140) {
			glColor3ub(0, 0, 0);
			drawText("I WILL BE FINE HERE....", 80, 482);
		}
		else if (count > 10200 && count < 10380) {
			glColor3ub(0, 0, 0);
			drawText("ADIMRAL CHENG!!!!, NO... I WON'T LEAVE YOU", 13, 481);
		}
		else if (count > 10440 && count < 10620) {
			glColor3ub(0, 0, 0);
			drawText("NOW PRINCESS... YOU WILL NOT LEAVE HIM", 255, 292);
		}
		else if (count > 10680 && count < 10860) {
			glColor3ub(0, 0, 0);
			drawText("FOR YOU WILL LEAVE WITH ME", 294, 283);
		}
		else if (count > 10920 && count < 11160) {
			glColor3ub(0, 0, 0);
			drawText("COME HERE IF YOU WISH NOT TO BE HURT", 226, 285);
		}
		else if (count > 11220 && count < 11460) {
			glColor3ub(0, 0, 0);
			drawText("NOW NOW, SLOW YOUR HORSES DOWN AND LETS SETTLE IT HERE", 50, 104);
		}
		else if (count > 11520 && count < 11640) {
			glColor3b(0, 0, 0);
			drawTextBig("?", 291, 297);
		}
}
	else if (count > 11760 && count < 12120) {
	skySC_10();
	hangTuah();

	//animation


	//display text
	if (count > 11820 && count < 12120) {
		glColor3ub(0, 0, 0);
		drawText("I AM HANG TUAH OF MALACCA AND I WILL SAVE THE PRINCESS", 29, 470);
	}
}
	else if (count > 12120 && count < 12420) {
	blackscreen();
	glColor3ub(255, 255, 255);
	drawTextBig("TO BE CONTINUE......", 149, 274);
}

	glutSwapBuffers();
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 500, 500, 0);
	glMatrixMode(GL_MODELVIEW);

}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	
	glutInitWindowPosition(200, 100);
	glutInitWindowSize(500, 500);

	glutCreateWindow("SATRIA");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(1000, timer, 0);

	glutMainLoop();
}