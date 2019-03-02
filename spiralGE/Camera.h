#pragma once
#include <glm/mat4x4.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
namespace sge {
	class Camera // This is compatible to objects whose vertex shader support cameras 
	{
		glm::mat4 m_projection= glm::mat4(1.0), m_view = glm::mat4(1.0);
	public:
		unsigned int fov = 90;
		Camera(const float minRendDist,const float maxRendDist, const unsigned int scrWidth, const unsigned int scrHeight);
		~Camera();
	};
}

