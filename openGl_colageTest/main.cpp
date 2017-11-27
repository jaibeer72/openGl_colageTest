#include<GL\glew.h>
#include<glfw3.h>

#include<SOIL.h>
#include<iostream>
#define _USE_MATH_DEFINES
#include<math.h>


//GLM all headers required 
#include<glm\glm.hpp>
#include<glm\gtc\matrix_transform.hpp>
#include<glm\gtc\type_ptr.hpp>

int WIDTH = 720, HEIGHT = 720;


GLuint textureID;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

bool gamePaused = false;


GLboolean locked = GL_FALSE;
GLfloat alpha = 210.0f, beta = -70.0f, zoom = 2.0f;
GLfloat cursorX, cursorY;
bool freeze;

void drawCubes()
{
	//glEnable(GL_TEXTURE_2D);
	//glBindTexture(GL_TEXTURE_2D, textureID);
	//glBegin(GL_QUADS);
	//glTexCoord2f(-1, -1);
	//glVertex3f(1.0f, 1.0f, 0.0f);
	//glTexCoord2f(0, 1);
	//glVertex3f(-1.0f, 1.0f, 0.0f);
	//glTexCoord2f(0, 0);
	//glVertex3f(-1.0f, -1.0f, 0.0f);
	//glTexCoord2f(1, 0);
	//glVertex3f(1.0f, -1.0f, 0.0f);
	//glEnd();
	glPointSize(10.0f);
	glBegin(GL_POINTS);
	
	//glTexCoord2f(-0.5f, -0.5f);
	glVertex3f(-0.5f, -0.5f, -0.5f); glColor4f(0.2f,0.3f,0.8f,1.0f);
	glVertex3f(0.5f, -0.5f, -0.5f);	glColor4f(0.2f, 0.3f, 0.8f, 1.0f);
	glVertex3f(0.5f, 0.5f, -0.5f); glColor4f(0.2f, 0.3f, 0.8f, 1.0f);
	glVertex3f(0.5f, 0.5f, -0.5f); glColor4f(0.1f, 0.1f, 0.8f, 1.0f);
	glVertex3f(-0.5f, 0.5f, -0.5f); glColor4f(0.1f, 0.3f, 0.8f, 1.0f);
	glVertex3f(-0.5f, -0.5f, -0.5f); glColor4f(0.1f, 0.3f, 0.8f, 1.0f);
	glEnd();
	glBegin(GL_POINTS);
	//glBegin(GL_LINES);
	//glBegin(GL_POLYGON);
	glVertex3f(-0.5f, -0.5f, 0.5f); glColor4f(0.2f, 1.0f, 0.4f, 1.0f);
	glVertex3f(0.5f, -0.5f, 0.5f); glColor4f(0.2f, 1.0f, 0.1f, 1.0f);
	glVertex3f(0.5f, 0.5f, 0.5f); glColor4f(0.2f, 1.0f, 0.1f, 1.0f);
	glVertex3f(0.5f, 0.5f, 0.5f); glColor4f(0.2f, 1.0f, 0.1f, 1.0f);
	glVertex3f(-0.5f, 0.5f, 0.5f); glColor4f(0.2f, 1.0, 0.1f, 1.0f);
	glVertex3f(-0.5f, -0.5f, 0.5f); glColor4f(0.2f, 1.0f, 0.1f, 1.0f);
	//glEnd();
	glBegin(GL_POINTS);
	//glBegin(GL_LINES);
	//glBegin(GL_POLYGON);
	glVertex3f(-0.5f, 0.5f, 0.5f); glColor4f(0.2f, 0.3f, 0.1f, 1.0f);
	glVertex3f(-0.5f, 0.5f, -0.5f); glColor4f(0.2f, 0.3f, 0.1f, 1.0f);
	glVertex3f(-0.5f, -0.5f, -0.5f); glColor4f(0.2f, 0.3f, 0.1f, 1.0f);
	glVertex3f(-0.5f, -0.5f, -0.5f); glColor4f(0.2f, 0.f, 0.1f, 1.0f);
	glVertex3f(-0.5f, -0.5f, 0.5f); glColor4f(0.2f, 0.3f, 0.1f, 1.0f);
	glVertex3f(-0.5f, 0.5f, 0.5f); glColor4f(0.2f, 0.3f, 0.3f, 1.0f);
	glEnd();
	glBegin(GL_POINTS);
	//glBegin(GL_LINES);
	//glBegin(GL_POLYGON);
	glVertex3f(0.5f, 0.5f, 0.5f); glColor4f(0.2f, 0.3f, 0.1f, 1.0f);
	glVertex3f(0.5f, 0.5f, -0.5f); glColor4f(0.2f, 0.3f, 0.3f, 1.0f);
	glVertex3f(0.5f, -0.5f, -0.5f); glColor4f(0.2f, 0.3f, 0.1f, 1.0f);
	glVertex3f(0.5f, -0.5f, -0.5f); glColor4f(0.2f, 0.3f, 0.1f, 1.0f);
	glVertex3f(0.5f, -0.5f, 0.5f); glColor4f(0.2f, 0.3f, 0.3f, 1.0f);
	glVertex3f(0.5f, 0.5f, 0.5f); glColor4f(0.2f, 0.3f, 0.1f, 1.0f);
	glEnd();
	glBegin(GL_POINTS);
	//glBegin(GL_LINES);
	//glBegin(GL_POLYGON);
	glVertex3f(-0.5f, -0.5f, -0.5f); glColor4f(0.2f, 0.3f, 0.1f, 1.0f);
	glVertex3f(0.5f, -0.5f, -0.5f); glColor4f(0.2f, 0.1f, 0.3f, 1.0f);
	glVertex3f(0.5f, -0.5f, 0.5f); glColor4f(0.2f, 0.3f, 0.1f, 1.0f);
	glVertex3f(0.5f, -0.5f, 0.5f); glColor4f(0.2f, 0.3f, 0.1f, 1.0f);
	glVertex3f(-0.5f, -0.5f, 0.5f); glColor4f(0.2f, 0.1f, 0.3f, 1.0f);
	glVertex3f(-0.5f, -0.5f, -0.5f); glColor4f(0.2f, 0.3f, 0.1f, 1.0f);
	glEnd();
	//	glBegin(GL_LINES);
	//glBegin(GL_POLYGON);
	glBegin(GL_POINTS);
	glVertex3f(-0.5f, 0.5f, -0.5f); glColor4f(1.0f, 0.3f, 0.1f, 1.0f);
	glVertex3f(0.5f, 0.5f, -0.5f); glColor4f(1.0f, 0.2f, 0.3f, 1.0f);
	glVertex3f(0.5f, 0.5f, 0.5f); glColor4f(1.0f, 0.3f, 0.1f, 1.0f);
	glVertex3f(0.5f, 0.5f, 0.5f); glColor4f(1.0f, 0.3f, 0.1f, 1.0f);
	glVertex3f(-0.5f, 0.5f, 0.5f); glColor4f(1.0f, 0.5f, 0.3f, 1.0f);
	glVertex3f(-0.5f, 0.5f, -0.5f); glColor4f(1.0f, 0.3f, 0.1f, 1.0f);
	glEnd();
}

// Key Callback
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action != GLFW_PRESS)
		return;
	switch (key)
	{
	case GLFW_KEY_ESCAPE:
		glfwSetWindowShouldClose(window, GL_TRUE);
		break;
	case GLFW_KEY_SPACE:
		freeze = !freeze;
		break;
	case GLFW_KEY_LEFT:
		alpha += 5.0f;
		break;
	case GLFW_KEY_RIGHT:
		alpha -= 5.0f;
		break;
	case GLFW_KEY_UP:
		beta -= 5.0f;
		break;
	case GLFW_KEY_DOWN:
		beta += 5.0f;
		break;
	case GLFW_KEY_PAGE_UP:
		zoom -= 0.25f;
		if (zoom < 0.0f)
			zoom = 0.0f;
		break;
	case GLFW_KEY_PAGE_DOWN:
		zoom += 0.25f;
		break;
	default:
		break;
	}
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	if (button != GLFW_MOUSE_BUTTON_LEFT)
		return;
	if (action == GLFW_PRESS)
	{
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		locked = GL_TRUE;
	}
	else
	{
		locked = GL_FALSE;
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	}
}

void cursor_position_callback(GLFWwindow* window, double x, double y)
{
	//if the mouse button is pressed
	if (locked)
	{
		alpha += (GLfloat)(x - cursorX) / 10.0f;
		beta += (GLfloat)(y - cursorY) / 10.0f;
	}
	//update the cursor position
	cursorX = (int)x;
	cursorY = (int)y;
}
void scroll_callback(GLFWwindow* window, double x, double y)
{
	zoom += (float)y / 4.0f;
	if (zoom < 0.0f)
		zoom = 0.0f;
}

GLuint loadTexture(const char * filename) {
	GLuint textureID;
	unsigned char * image;
	int width, height;
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);
	// Set our texture parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// Set texture filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// Load, create texture and generate mipmaps
	image = SOIL_load_image(filename, &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);

	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);
	return textureID;
}
void init()
{
	//GLfloat LightPos[] = { 10.0f, 10.0f, -10.0f, 1.0f };
	//GLfloat LightAmb[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	//GLfloat LightDif[] = { 0.6f, 0.6f, 0.6f, 1.0f };
	//GLfloat LightSpc[] = { 0.9f, 0.9f, 0.9f, 1.0f };

	//glLightfv(GL_LIGHT1, GL_POSITION, LightPos);
	//glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmb);
	//glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDif);
	//glLightfv(GL_LIGHT1, GL_SPECULAR, LightSpc);

	////glLightfv(GL_LIGHT0, GL_SPECULAR, LightSpc);

	////glEnable(GL_LIGHT0);
	//glEnable(GL_LIGHT1);
	//glShadeModel(GL_SMOOTH);
	//glEnable(GL_LIGHTING);
	//glEnable(GL_COLOR_MATERIAL);
	//glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	//GLfloat specReflection[] = { 0.8f, 0.8f, 0.8f, 1.0f };
	//glMaterialfv(GL_FRONT, GL_SPECULAR, specReflection);
	//glMateriali(GL_FRONT, GL_SHININESS, 56);

}

int main()
{
	glfwInit();
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", NULL, NULL);

	glfwSetKeyCallback(window, key_callback);
	glfwMakeContextCurrent(window);
	glViewport(0, 0, WIDTH, HEIGHT);
	glfwSetKeyCallback(window, key_callback);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	//textureID[0] = loadTexture("1.jpg");
	//mouse button callback
	glfwSetMouseButtonCallback(window, mouse_button_callback);

	//mouse movement callback
	glfwSetCursorPosCallback(window, cursor_position_callback);

	//mouse scroll callback
	glfwSetScrollCallback(window, scroll_callback);

	glEnable(GL_DEPTH_TEST);

	//GLuint texID = loadTexture("./assets/platform.jpg");

	do {

		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		init();
		float ratio;
		int w, h;
		glfwGetFramebufferSize(window, &w, &h);
		framebuffer_size_callback(window, w, h);
		ratio = (float)w / (float)h;


	//	glEnable(GL_TEXTURE_2D);
		//glEnable(GL_BLEND | GL_ALPHA_TEST);
		//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		//glBindTexture(GL_TEXTURE_2D, texID);

		glMatrixMode(GL_TEXTURE);
		glLoadIdentity();
		glScalef(1.0f, -1.0f, 1.0f);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glTranslatef(0.0, 0.0, -2.0);
		glRotatef(beta, 1.0, 0.0, 0.0);
		// rotate by alpha degrees around the z-axis
		glRotatef(alpha, 0.0, 0.0, 1.0);

		
		drawCubes();
		/*glEnable(GL_NORMALIZE);
		glBegin(GL_QUADS);*/
		//glTexCoord2f(1.0f, 0.0f); glVertex3f(0.18f, -0.18f, 0.0f);  // Top Left Of The Texture and Quad
		//glTexCoord2f(1.0f, 1.0f); glVertex3f(0.18f, 0.18f, 0.0f); // Top Right Of The Texture and Quad
		//glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.18f, 0.18f, 0.0f); // Bottom Right Of The Texture and Quad
		//glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.18f, -0.18f, 0.0f);   // Bottom Left Of The Texture and Quad



		//glEnd();

		//glBindTexture(GL_TEXTURE_2D, 0);
		glfwSwapBuffers(window);
		glfwPollEvents();

	} while (!glfwWindowShouldClose(window));
	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	const float fovY = 45.0f;
	const float front = 0.1f;
	const float back = 128.0f;
	float ratio = 1.0f;
	if (height > 0)
		ratio = (float)width / (float)height;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	const double DEG2RAD = 3.14159265 / 180;
	// tangent of half fovY
	double tangent = tan(fovY / 2 * DEG2RAD);
	// half height of near plane
	double height_f = front * tangent;
	// half width of near plane
	double width_f = height_f * ratio;

	//Create the projection matrix based on the near clipping 
	//plane and the location of the corners
	glFrustum(-width_f, width_f, -height_f, height_f, front, back);
}