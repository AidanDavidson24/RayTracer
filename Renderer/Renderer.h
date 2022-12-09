#pragma once
#include "Canvas.h"
#include "../Math/Ray.h"
#include "../Object/Object.h"
#include "../Object/Scene.h"
#include "Camera.h"
#include <SDL.h>

class Renderer
{
public:
	Renderer() = default;

	bool Initialize();
	void Shutdown();
	bool CreateWindow(int width, int height);
	
	void Render(Canvas& canvas, Scene& scene, Camera& camera, int samples = 5);

	void CopyCanvas(const Canvas& canvas);
	void Present();

	friend class Canvas;

private:
	SDL_Window* m_window{ nullptr };
	SDL_Renderer* m_renderer{ nullptr };

private:
	color3 GetBackgroundFromRay(const Ray& ray);
};