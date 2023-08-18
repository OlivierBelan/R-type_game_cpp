#include "IComponent.hpp"
#include "ISystem.hpp"
// #include "Manager.hpp"
#include "GameEngine.hpp"
#include "TestSystem.hpp"
#include <iostream>
#include <set>
#include <string>

void test_Entity()
{
	ECS::Manager lol;
	lol.createEntity();
	lol.createEntity();
	lol.createEntity();
	lol.createEntity();
	lol.createEntity();
	lol.createEntity();
	lol.createEntity();
	lol.createEntity();
	lol.createEntity();
	lol.createEntity();
	lol.printInfo();
	lol.destroyEntity(5);
	lol.printInfo();
	lol.createEntity();
	lol.printInfo();
}

void test_Component()
{
	// ECS::Manager lol;
	// ECS::A componentA;
	// ECS::B componentB;
	// ECS::Entity entityA = lol.createEntity();
	// ECS::Entity entityB = lol.createEntity();

	// lol.createComponent(componentA, componentB);
	// lol.printInfo();
	// ECS::SystemeA systemA(12, {ECS::A::type, ECS::B::type}, std::make_shared<ECS::Manager>(lol));
	// ECS::SystemeB systemB(11, {ECS::A::type}, std::make_shared<ECS::Manager>(lol));
	// // ECS::SystemeA test(12, std::set<ComponentType>(ECS::A::type, ECS::B::type));
	// lol.addComponentToEntity(entityA, std::make_shared<ECS::A>(componentA), std::make_shared<ECS::B>(componentB));
	// // lol.addComponentToEntity(entityB, std::make_shared<ECS::B>(componentB));
	// lol.addComponentToEntity(entityB, std::make_shared<ECS::A>(componentA));
	// // lol.printInfo();
	// lol.printInfo();

	// lol.addSystem(std::make_shared<ECS::SystemeA>(systemA));
	// lol.addSystem(std::make_shared<ECS::SystemeB>(systemB));
	// lol.printInfo();
	// lol.initSystem();
	// lol.addEntityToSystem(entityA);
	// lol.addEntityToSystem(entityB);
	// // lol.destroyComponentFromEntity(entityA, ECS::A::type);
	// lol.printInfo();
	// // for (auto i = 0; i < 10; i++)
	// lol.updateSystem();
	// // test.run();
	// // test.update();
	// // lol.updateSystem(12);
	// // lol.destroyComponentFromEntity(1, ECS::A::type);
	// // lol.createComponent(a, c, d, e);
	// // lol.createComponent12);
}

void test_Engine()
{
	// GameEngine engine;
	// engine.init();
	// engine.run();
}

int main()
{
	// test_Component();
	test_Engine();
	// std::shared_ptr<int> a = std::make_shared<int>(12);
	// std::shared_ptr<int> b = a;
	// // b = std::make_shared<int>(14);
	// *a = 14;
	// if (a == b) {
	// 	std::cout << "A = " << a << " B = " << b << "\n";
	// }
	// bool test = false;
	// std::cout << test << std::endl;
	// test = false;
	// std::cout << test << std::endl;
	return (0);
}