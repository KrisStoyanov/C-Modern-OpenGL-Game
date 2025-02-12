#include "GameEngine.h"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

GameEngine gameEngine;

int main(int argc, char **argv) 
{
	gameEngine.Initialise(800, 600, "Super Lawn Bowl", argc, argv);

	gameEngine.Setup();

	PhysicsObject physPlane(0.0f, new PlaneCollider(glm::vec3(0.0f, 1.0f, 0.0f)));
	PhysicsObject physSphere(3.0f, new SphereCollider(2));
	PhysicsObject physSphere1(6.0f, new SphereCollider(4));
	PhysicsObject physSphere2(6.0f, new SphereCollider(4));
	PhysicsObject physSphere3(6.0f, new SphereCollider(4));
	PhysicsObject physSphere4(6.0f, new SphereCollider(4));
	PhysicsObject physSphere5(6.0f, new SphereCollider(4));
	PhysicsObject physSphere6(6.0f, new SphereCollider(4));

	gameEngine.AddPhysObject(&physPlane);
	gameEngine.AddPhysObject(&physSphere);
	gameEngine.AddPhysObject(&physSphere1);
	gameEngine.AddPhysObject(&physSphere2);
	gameEngine.AddPhysObject(&physSphere3);
	gameEngine.AddPhysObject(&physSphere4);
	gameEngine.AddPhysObject(&physSphere5);
	gameEngine.AddPhysObject(&physSphere6);

	gameEngine.AddGameObject(new GameObject("jack", glm::vec3(0.0, 6.0, 90.0), glm::vec3(0.0, 0.0, -1.0), gameEngine.meshManager.GetMesh("SmallSphere"), gameEngine.textureManager.GetTexture("ShinyMetal"), gameEngine.materialManager.GetMaterial("reflective"), gameEngine.shaderManager.GetShader("toonOutline"), &physSphere), false);
	gameEngine.AddGameObject(new GameObject("ball1", glm::vec3(15.0, 6.0, 100.0), glm::vec3(0.0, 0.0, -1.0), gameEngine.meshManager.GetMesh("MediumSphere"),gameEngine.textureManager.GetTexture("BasicMetal"), gameEngine.materialManager.GetMaterial("reflective"), gameEngine.shaderManager.GetShader("toonOutline"), &physSphere1), false);	
	gameEngine.AddGameObject(new GameObject("ball2", glm::vec3(30.0, 6.0, 100.0), glm::vec3(0.0, 0.0, -1.0), gameEngine.meshManager.GetMesh("MediumSphere"), gameEngine.textureManager.GetTexture("BasicMetal"), gameEngine.materialManager.GetMaterial("reflective"), gameEngine.shaderManager.GetShader("toonOutline"), &physSphere2), false);
	gameEngine.AddGameObject(new GameObject("ball3", glm::vec3(45.0, 6.0, 100.0), glm::vec3(0.0, 0.0, -1.0), gameEngine.meshManager.GetMesh("MediumSphere"), gameEngine.textureManager.GetTexture("BasicMetal"), gameEngine.materialManager.GetMaterial("reflective"), gameEngine.shaderManager.GetShader("toonOutline"), &physSphere3), false);

	gameEngine.AddGameObject(new GameObject("ball4", glm::vec3(-15.0, 6.0, 100.0), glm::vec3(0.0, 0.0, -1.0), gameEngine.meshManager.GetMesh("MediumSphere"), gameEngine.textureManager.GetTexture("DustyMetal"), gameEngine.materialManager.GetMaterial("reflective"), gameEngine.shaderManager.GetShader("toonOutline"), &physSphere4), false);
	gameEngine.AddGameObject(new GameObject("ball5", glm::vec3(-30.0, 6.0, 100.0), glm::vec3(0.0, 0.0, -1.0), gameEngine.meshManager.GetMesh("MediumSphere"), gameEngine.textureManager.GetTexture("DustyMetal"), gameEngine.materialManager.GetMaterial("reflective"), gameEngine.shaderManager.GetShader("toonOutline"), &physSphere5), false);
	gameEngine.AddGameObject(new GameObject("ball6", glm::vec3(-45.0, 6.0, 100.0), glm::vec3(0.0, 0.0, -1.0), gameEngine.meshManager.GetMesh("MediumSphere"), gameEngine.textureManager.GetTexture("DustyMetal"), gameEngine.materialManager.GetMaterial("reflective"), gameEngine.shaderManager.GetShader("toonOutline"), &physSphere6), false);
	
	gameEngine.AddGameObject(new GameObject("green", glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 0.0, 0.0), gameEngine.meshManager.GetMesh("GrassMesh"), gameEngine.textureManager.GetTexture("Grass"), gameEngine.materialManager.GetMaterial("dim"), gameEngine.shaderManager.GetShader("lit")), false);

	gameEngine.AddGameObject(new GameObject("ditch", glm::vec3(0.0, 0.0, -550.0), glm::vec3(0.0, 0.0, 0.0), gameEngine.meshManager.GetMesh("FieldMesh"), gameEngine.textureManager.GetTexture("Field"), gameEngine.materialManager.GetMaterial("dim"), gameEngine.shaderManager.GetShader("lit")), false);

	gameEngine.AddGameObject(new GameObject("boundaries", glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 0.0, 0.0), gameEngine.meshManager.GetMesh("Boundaries"), gameEngine.textureManager.GetTexture("Stone"), gameEngine.materialManager.GetMaterial("basic"), gameEngine.shaderManager.GetShader("lit")), false);

	//gameEngine.AddGameObject(new GameObject("clubhouseTeamOne", glm::vec3(-100.0, 25.0, -800.0), glm::vec3(0.0, 0.0, 0.0), gameEngine.modelManager.GetModel("Clubhouse"), gameEngine.shaderManager.GetShader("lit")),false);
	//gameEngine.AddGameObject(new GameObject("clubhouseTeamTwo", glm::vec3(100.0, 25.0, -800.0), glm::vec3(0.0, 0.0, 0.0), gameEngine.modelManager.GetModel("Clubhouse"), gameEngine.shaderManager.GetShader("lit")), false);

	//gameEngine.AddGameObject(new GameObject("warehouse", glm::vec3(0.0, 0.0, -500.0), glm::vec3(0.0, 0.0, 0.0), gameEngine.modelManager.GetModel("Warehouse"), gameEngine.shaderManager.GetShader("lit")), false);

	gameEngine.gameManager.GetJack(gameEngine.FindGameObject("jack"));
	gameEngine.gameManager.AddLawnBall(gameEngine.FindGameObject("ball1"), 0);
	gameEngine.gameManager.AddLawnBall(gameEngine.FindGameObject("ball2"), 0);
	gameEngine.gameManager.AddLawnBall(gameEngine.FindGameObject("ball3"), 0);
	gameEngine.gameManager.AddLawnBall(gameEngine.FindGameObject("ball4"), 1);
	gameEngine.gameManager.AddLawnBall(gameEngine.FindGameObject("ball5"), 1);
	gameEngine.gameManager.AddLawnBall(gameEngine.FindGameObject("ball6"), 1);


	//Skybox:
	gameEngine.AddGameObject(new GameObject("skyboxTop", glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 0.0, 0.0), gameEngine.meshManager.GetMesh("SBTop"), gameEngine.textureManager.GetTexture("SBTop"), gameEngine.materialManager.GetMaterial("basic"), gameEngine.shaderManager.GetShader("unlit")), false);
	gameEngine.AddGameObject(new GameObject("skyboxLeft", glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 0.0, 0.0), gameEngine.meshManager.GetMesh("SBLeft"), gameEngine.textureManager.GetTexture("SBRight"), gameEngine.materialManager.GetMaterial("basic"), gameEngine.shaderManager.GetShader("unlit")), false);
	gameEngine.AddGameObject(new GameObject("skyboxRight", glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 0.0, 0.0), gameEngine.meshManager.GetMesh("SBRight"), gameEngine.textureManager.GetTexture("SBLeft"), gameEngine.materialManager.GetMaterial("basic"), gameEngine.shaderManager.GetShader("unlit")), false);
	gameEngine.AddGameObject(new GameObject("skyboxBottom", glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 0.0, 0.0), gameEngine.meshManager.GetMesh("SBBottom"), gameEngine.textureManager.GetTexture("SBBottom"), gameEngine.materialManager.GetMaterial("basic"), gameEngine.shaderManager.GetShader("unlit")), false);
	gameEngine.AddGameObject(new GameObject("skyboxFront", glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 0.0, 0.0), gameEngine.meshManager.GetMesh("SBFront"), gameEngine.textureManager.GetTexture("SBFront"), gameEngine.materialManager.GetMaterial("basic"), gameEngine.shaderManager.GetShader("unlit")), false);
	gameEngine.AddGameObject(new GameObject("skyboxBack", glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 0.0, 0.0), gameEngine.meshManager.GetMesh("SBBack"), gameEngine.textureManager.GetTexture("SBBack"), gameEngine.materialManager.GetMaterial("basic"), gameEngine.shaderManager.GetShader("unlit")), false);

	gameEngine.Start();

	//gameEngine.cameraManager.CleanMemory();
	//gameEngine.lightManager.CleanMemory();
	//gameEngine.materialManager.CleanMemory();
	//gameEngine.meshManager.CleanMemory();
	//gameEngine.shaderManager.CleanMemory();
	//gameEngine.textureManager.CleanMemory();
}
