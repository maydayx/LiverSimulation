#pragma once
#include "Mesh.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

// �ʵ�䵯��
struct SprP {
	unsigned int v1;
	unsigned int v2;
	float length;
};

// Լ������
struct SprC {
	unsigned int v;
	glm::vec3 pos;
};

class Spring
{
public:
	Spring(Mesh* mesh_ptr) : mesh_ptr_(mesh_ptr) {
		initSprings();
		velocities_.resize(mesh_ptr->vertices.size(), glm::vec3(0.0f, 0.0f, 0.0f));
		accelerations_.resize(mesh_ptr->vertices.size(), glm::vec3(0.0f, 0.0f, 0.0f));
	}

	void update(float delta_time);
	void restoreVelocities();
	void restoreParticles();

private:
	Mesh* mesh_ptr_;
	std::vector<SprP> springs_p_;
	std::vector<SprC> springs_c_;

	float c_p = 2.0f, c_c = 2.0f; // �ʵ��������Լ�����õĳ�����
	std::vector<glm::vec3> accelerations_;
	std::vector<glm::vec3> velocities_;

	void initSprings();
	void updateAccelerations();
	void updateVelocities(float delta_time);
	void updatePositions(float delta_time);
};

