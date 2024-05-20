#pragma once

typedef struct ncSpring {
	struct ncBody* body1;
	struct ncBody* body2;
	float restLength;
	float k; //stiffness, the higher the value the bigger the force to keep the bodies together

	struct ncSpring* prev;
	struct ncSpring* next;
} ncSpring_t;

extern ncSpring_t* ncSprings;

ncSpring_t* CreateSpring(struct ncBody* body1, struct ncBody* body2, float restLength, float k);
void AddSpring(ncSpring_t* spring);
void DestroySpring(ncSpring_t* spring);
void DestroyAllSprings();

void ApplySpringForce(ncSpring_t* springs);