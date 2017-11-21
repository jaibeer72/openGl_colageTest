#include<GL\glew.h>
#include<glfw3.h>
#include<iostream>

#define _USE_MATH_DEFINES
#include<math.h>

//GLM all headers required 
#include<glm\glm.hpp>
#include<glm\gtc\matrix_transform.hpp>
#include<glm\gtc\type_ptr.hpp>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void drawCubes();
typedef struct Vertex
{
	glm::vec3 position; 
	glm::vec4 color;
};
void drawPoint(Vertex v1, GLfloat size) {
	glPointSize(size); 
	glBegin(GL_POINTS);
	glColor4f(v1.color.r, v1.color.g, v1.color.b, v1.color.a);
	glVertex3f(v1.position.x, v1.position.y, v1.position.z);
	glEnd();
}

void drawPointsDemo(int width, int height) {
	Vertex vert;
	GLfloat size = 5.0f;
	for (GLfloat x = 0.0f; x <= 1.0f; x += 0.2f, size += 5)
	{
		vert.position = glm::vec3(x, 0.0f, 0.0f);
		vert.color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
		drawPoint(vert, size);
	}
}

//Global Variables 
const int width=700; 
const int height = 700;
GLboolean locked = GL_FALSE;
GLfloat alpha = 210.0f, beta = -70.0f, zoom = 2.0f;
GLfloat cursorX, cursorY; 
bool freeze; 

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
	this 
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

int main(void) {
	GLFWwindow* window; 
	if (!glfwInit())exit(EXIT_FAILURE);
	window = glfwCreateWindow(width, height, "window API", NULL, NULL); 
	if (!glewInit())exit(EXIT_FAILURE); 
	glfwMakeContextCurrent(window); 
	Vertex vert;
	vert.position = glm::vec3(0.0f, 0.0f, 0.0f);
	vert.color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);

	glfwSetKeyCallback(window, key_callback);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	//mouse button callback
	glfwSetMouseButtonCallback(window, mouse_button_callback);

	//mouse movement callback
	glfwSetCursorPosCallback(window, cursor_position_callback);

	//mouse scroll callback
	glfwSetScrollCallback(window, scroll_callback);

	glEnable(GL_DEPTH_TEST);


	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

		float ratio; 
		int w, h; 
		glfwGetFramebufferSize(window, &w, &h);
		framebuffer_size_callback(window, w, h);
		ratio = (float)w / (float)h; 
		//glViewport(0, 0, w, h); 
		//glClear(GL_COLOR_BUFFER_BIT); 
		glMatrixMode(GL_MODELVIEW); 
		glLoadIdentity(); 
		glTranslatef(0.0, 0.0, -2.0);
		glRotatef(beta, 1.0, 0.0, 0.0);
		// rotate by alpha degrees around the z-axis
		glRotatef(alpha, 0.0, 0.0, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//drawPointsDemo(width, height); 
		
		drawCubes();
		glfwSwapBuffers(window); 
		glfwPollEvents(); 

	}
	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
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

void drawCubes()
{
	Vertex v;
	glBegin(GL_TRIANGLES);
		glVertex3f(-0.5f, -0.5f, -0.5f); glColor4f(0.2f,0.3f,0.8f,1.0f);
		glVertex3f(0.5f, -0.5f, -0.5f);	glColor4f(0.2f, 0.3f, 0.8f, 1.0f);
		glVertex3f(0.5f, 0.5f, -0.5f); glColor4f(0.2f, 0.3f, 0.8f, 1.0f);
		glVertex3f(0.5f, 0.5f, -0.5f); glColor4f(0.1f, 0.1f, 0.8f, 1.0f);
		glVertex3f(-0.5f,0.5f, -0.5f); glColor4f(0.1f, 0.3f, 0.8f, 1.0f);
		glVertex3f(-0.5f, -0.5f, -0.5f); glColor4f(0.1f, 0.3f, 0.8f, 1.0f);
		glEnd();
		glBegin(GL_TRIANGLES);
		//glBegin(GL_LINES);
		//glBegin(GL_POLYGON);
		glVertex3f(-0.5f, -0.5f, 0.5f); glColor4f(0.2f, 1.0f, 0.4f, 1.0f);
		glVertex3f(0.5f, -0.5f, 0.5f); glColor4f(0.2f, 1.0f, 0.1f, 1.0f);
		glVertex3f(0.5f, 0.5f, 0.5f); glColor4f(0.2f, 1.0f, 0.1f, 1.0f);
		glVertex3f(0.5f, 0.5f, 0.5f); glColor4f(0.2f, 1.0f, 0.1f, 1.0f);
		glVertex3f(-0.5f, 0.5f, 0.5f); glColor4f(0.2f, 1.0, 0.1f, 1.0f);
		glVertex3f(-0.5f, -0.5f, 0.5f); glColor4f(0.2f, 1.0f, 0.1f, 1.0f);
		glEnd();
		glBegin(GL_TRIANGLES);
		//glBegin(GL_LINES);
		//glBegin(GL_POLYGON);
		glVertex3f(-0.5f, 0.5f, 0.5f); glColor4f(0.2f, 0.3f, 0.1f, 1.0f);
		glVertex3f(-0.5f, 0.5f, -0.5f); glColor4f(0.2f, 0.3f, 0.1f, 1.0f);
		glVertex3f(-0.5f, -0.5f, -0.5f); glColor4f(0.2f, 0.3f, 0.1f, 1.0f);
		glVertex3f(-0.5f, -0.5f, -0.5f); glColor4f(0.2f, 0.f, 0.1f, 1.0f);
		glVertex3f(-0.5f,- 0.5f, 0.5f); glColor4f(0.2f, 0.3f, 0.1f, 1.0f);
		glVertex3f(-0.5f, 0.5f, 0.5f); glColor4f(0.2f, 0.3f, 0.3f, 1.0f);
		glEnd();
		glBegin(GL_TRIANGLES);
		//glBegin(GL_LINES);
		//glBegin(GL_POLYGON);
		glVertex3f(0.5f, 0.5f, 0.5f); glColor4f(0.2f, 0.3f, 0.1f, 1.0f);
		glVertex3f(0.5f, 0.5f, -0.5f); glColor4f(0.2f, 0.3f, 0.3f, 1.0f);
		glVertex3f(0.5f, -0.5f, -0.5f); glColor4f(0.2f, 0.3f, 0.1f, 1.0f);
		glVertex3f(0.5f, -0.5f, -0.5f); glColor4f(0.2f, 0.3f, 0.1f, 1.0f);
		glVertex3f(0.5f, -0.5f, 0.5f); glColor4f(0.2f, 0.3f, 0.3f, 1.0f);
		glVertex3f(0.5f, 0.5f, 0.5f); glColor4f(0.2f, 0.3f, 0.1f, 1.0f);
		glEnd();
		glBegin(GL_TRIANGLES);
		//glBegin(GL_LINES);
		//glBegin(GL_POLYGON);
		glVertex3f(-0.5f, -0.5f, -0.5f); glColor4f(0.2f, 0.3f, 0.1f, 1.0f);
		glVertex3f(0.5f,- 0.5f, -0.5f); glColor4f(0.2f, 0.1f, 0.3f, 1.0f);
		glVertex3f(0.5f, -0.5f, 0.5f); glColor4f(0.2f, 0.3f, 0.1f, 1.0f);
		glVertex3f(0.5f, -0.5f, 0.5f); glColor4f(0.2f, 0.3f, 0.1f, 1.0f);
		glVertex3f(-0.5f, -0.5f, 0.5f); glColor4f(0.2f, 0.1f, 0.3f, 1.0f);
		glVertex3f(-0.5f, -0.5f,- 0.5f); glColor4f(0.2f, 0.3f, 0.1f, 1.0f);
	glEnd();
	//	glBegin(GL_LINES);
	//glBegin(GL_POLYGON);
	glBegin(GL_TRIANGLES);
		glVertex3f(-0.5f, 0.5f, -0.5f); glColor4f(1.0f, 0.3f, 0.1f, 1.0f);
		glVertex3f(0.5f, 0.5f, -0.5f); glColor4f(1.0f, 0.2f, 0.3f, 1.0f);
		glVertex3f(0.5f, 0.5f, 0.5f); glColor4f(1.0f, 0.3f, 0.1f, 1.0f);
		glVertex3f(0.5f,0.5f, 0.5f); glColor4f(1.0f, 0.3f, 0.1f, 1.0f);
		glVertex3f(-0.5f, 0.5f, 0.5f); glColor4f(1.0f, 0.5f, 0.3f, 1.0f);
		glVertex3f(-0.5f, 0.5f, -0.5f); glColor4f(1.0f, 0.3f, 0.1f, 1.0f);
	glEnd();
}
