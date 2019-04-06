#include "shared.h"
#include "Population.h"
#include "Maze.h"



void drawPoint(Point2D p, ColorRGB c)
{
	float test = 2.f / (mapsize + 2);

	glColor3f(c.r, c.g, c.b);
	glVertex2f(-1 + (p.x + 1)*test + test / 2, -1 + (p.y + 1) * test + test / 2);
}
void drawMap(Maze *mainMaze, Individual *best)
{
	float test = 2.f / (mapsize + 2);
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	for (int i = 1; i < mapsize + 2; i++)
	{
		glVertex2f(-1 + i * test, 1 - test);
		glVertex2f(-1 + i * test, -1 + test);
		glVertex2f(-1 + test, -1 + i * test);
		glVertex2f(1 - test, -1 + i * test);

	}
	glEnd();

	glPointSize(10.f);
	glBegin(GL_POINTS);
	for (int i = 0; i < mapsize; i++)
	{
		for (int j = 0; j < mapsize; j++)
		{
			if (mainMaze->at(j,i) == 1)
				drawPoint(Point2D(j, i), ColorRGB(1.0, 0, 0));
		}
	}
	glEnd();
	glPointSize(10.f);
	glBegin(GL_POINTS);
	for(auto x : best->getvisiteds(mainMaze))
		drawPoint(Point2D(x.first, x.second), ColorRGB(0, 0, 1.0));
	glEnd();
}
void drawIndi(Individual *indi, ColorRGB a)
{
	glPointSize(5.f);
	glBegin(GL_POINTS);
	drawPoint(indi->position, a);

	glEnd();
}
void mainRender(Population * population, Maze *m, GLFWwindow *window)
{

	for (int i = 0; i < chromosomelength; i++)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.3, 0.3, 0.3, 1);
		glViewport(0, 0, 640, 640);
		drawMap(m,population->best);
		for (auto agent : population->individuals)
		{
			agent->update(i);
			drawIndi(agent, { 0,0,0 });
		}
		drawIndi(population->best, { 0,1,0 });

		glfwSwapBuffers(window);
		
	}
	

}
int main()
{
	Maze *m = new Maze();
//m->save("maze.txt");
	Population *pop = new Population();
	Population *newone;
	int index = 0;



	GLFWwindow* window;
	if (!glfwInit())
		return -1;

	window = glfwCreateWindow(640, 640, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	while (!glfwWindowShouldClose(window))
	{
		newone = new Population(pop, m);

		int total = 0;
		int total1 = 0;
		int total2 = 0;
		int target = pop->best->eatcount;
		for (auto x : pop->individuals)
		{
			if (x->eatcount == target)
				total++;
			else if (x->eatcount == target - 1)
				total1++;
			else if (x->eatcount == target - 2)
				total2++;
		}


		std::cout << "\nStep: " << index << " BestScore:" << pop->best->score << " BestEat:" << pop->best->eatcount;
		std::cout << "-eniyiler->" << total << " " << total1 << " " << total2 << std::endl;

		mainRender(pop, m, window);
		delete pop;
		pop = newone;
		index++;
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();

	

	return 0;
}