#include "Particle.hpp"
#include <iostream>
#include <vector>
#include <tuple>

class QuadTreeNode {
public:
	double x, y;
	double mass;
	double minX, minY, maxX, maxY;
	Particle* particle;
	bool isLeaf;
	std::vector<QuadTreeNode*> children;

	QuadTreeNode(double minX, double minY, double maxX, double maxY)
		:
		minX(minX),
		minY(minY),
		maxX(maxX),
		maxY(maxY),
		particle(nullptr),
		isLeaf(true),
		mass(0),
		x(0),
		y(0) {
		children.resize(4, nullptr);
	}

	~QuadTreeNode() {
		for (auto child : children) {
			delete child;
		}
	}

	bool contains(Particle* body) {
		return body->x_pos >= minX && body->x_pos < maxX && body->y_pos >= minY && body->y_pos < maxY;
	}

	int getQuadrant(Particle* body) {
		double midX = (minX + maxX) / 2;
		double midY = (minY + maxY) / 2;

		if (body->x_pos < midX) {
			if (body->y_pos < midY) return 0; // Top-left
			else return 2; // Bottom-left
		}
		else {
			if (body->y_pos < midY) return 1; // Top-right
			else return 3; // Bottom-right
		}
	}
	void insert(QuadTreeNode* node, Particle* particle) {
		if (!node->contains(particle)) return;
		if (node->isLeaf) {
			if (node->particle == nullptr) {
				node->particle = particle;
				node->mass = particle->mass;
				node->x = particle->x_pos;
				node->y = particle->y_pos;
			}
			else {
				Particle* existingBody = node->particle;
				node->particle = nullptr;
				node->isLeaf = false;

				double midX = (node->minX + node->maxX) / 2;
				double midY = (node->minY + node->maxY) / 2;

				node->children[0] = new QuadTreeNode(node->minX, node->minY, midX, midY);
				node->children[1] = new QuadTreeNode(midX, node->minY, node->maxX, midY);
				node->children[2] = new QuadTreeNode(node->minX, midY, midX, node->maxY);
				node->children[3] = new QuadTreeNode(midX, midY, node->maxX, node->maxY);

				insert(node->children[node->getQuadrant(existingBody)], existingBody);
				insert(node->children[node->getQuadrant(particle)], particle);
			}
		}
		else {
			node->x = (node->x * node->mass + particle->x_pos * particle->mass) / (node->mass + particle->mass);
			node->y = (node->y * node->mass + particle->y_pos * particle->mass) / (node->mass + particle->mass);
			node->mass += particle->mass;
		}
	}
	
	std::tuple<double, double, double> Compute_Mass(QuadTreeNode* root) {
		if (root->isLeaf) {

			//unsure if this is necessary?
			root->mass = particle->mass;
			root->x = particle->x_pos;
			root->y = particle->y_pos;

			return { root->particle->mass, root->particle->x_pos, root->particle->y_pos };
		}
		else
		{
			double totalMass = 0.0;
			double cmX = 0.0;
			double cmY = 0.0;

			for (QuadTreeNode* child : root->children) {
				if (child != nullptr) {
					std::tuple<double, double, double> childResult = Compute_Mass(child);
					double childMass = std::get<0>(childResult);
					double childX = std::get<1>(childResult);
					double childY = std::get<2>(childResult);
					totalMass += childMass;
					cmX += childX * childMass;
					cmY += childY * childMass;
				}
			}
			double centerX = cmX / totalMass;
			double centerY = cmY / totalMass;
			return std::make_tuple(totalMass, centerX, centerY);
		}
	}
};
