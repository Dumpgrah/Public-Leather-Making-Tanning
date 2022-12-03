class CfgPatches
{
	class ND_PeltChanges
	{
		units[] = {"Pelt_Base"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Gear_Consumables"};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class WildboarPelt;
	class RabbitPelt;
	class CowPelt;
	class PigPelt;
	class DeerPelt;
	class GoatPelt;
	class BearPelt;
	class WolfPelt;
	class SheepPelt;
	class MouflonPelt;
	class BoneHook: Inventory_Base
	{
		varQuantityInit = 1;
		varQuantityMin = 0;
		varQuantityMax = 4;
		varQuantityDestroyOnMin = 1;
		canBeSplit = 1;
	};
	class GardenLime: Inventory_Base
	{
		weight = 0.01;
		canBeSplit = 1;
	};
	class TannedLeather: Inventory_Base
	{
		varQuantityMax = 24;
		inventorySlot[] = {"Material_Shelter_Leather","DryRackLeather"};
	};
	class CleanedPelt_Base: Inventory_Base{};
	class CleanedWildboarPelt: CleanedPelt_Base
	{
		scope = 2;
		displayName = "A cleaned and prepared Wildboar Pelt";
		descriptionShort = "A pelt from a wild Boar ready for being tanned into leather or used for other purpose's";
		model = "\dz\gear\consumables\Pelt_Wildboar.p3d";
		weight = 420;
		itemSize[] = {5,3};
		inventorySlot[] = {"DryRackLeather"};
	};
	class CleanedRabbitPelt: CleanedPelt_Base
	{
		scope = 2;
		displayName = "A cleaned and prepared Rabbit Pelt";
		descriptionShort = "A pelt from a Rabbit ready for being tanned into leather or used for other purpose's";
		model = "\dz\gear\consumables\Pelt_Rabbit.p3d";
		weight = 220;
		itemSize[] = {3,2};
		inventorySlot[] = {"DryRackLeather"};
	};
	class CleanedCowPelt: CleanedPelt_Base
	{
		scope = 2;
		displayName = "A cleaned and prepared Cow Pelt";
		descriptionShort = "A pelt from a cow ready for being tanned into leather or used for other purpose's";
		model = "\dz\gear\consumables\Pelt_Cow.p3d";
		weight = 960;
		itemSize[] = {7,3};
		inventorySlot[] = {"DryRackLeather"};
	};
	class CleanedPigPelt: CleanedPelt_Base
	{
		scope = 2;
		displayName = "A cleaned and prepared Pig Pelt";
		descriptionShort = "A pelt from a pig ready for being tanned into leather or used for other purpose's";
		model = "\dz\gear\consumables\Pelt_Pig.p3d";
		weight = 420;
		itemSize[] = {5,3};
		inventorySlot[] = {"DryRackLeather"};
	};
	class CleanedDeerPelt: CleanedPelt_Base
	{
		scope = 2;
		displayName = "A cleaned and prepared Deer Pelt";
		descriptionShort = "A pelt from a deer ready for being tanned into leather or used for other purpose's";
		model = "\dz\gear\consumables\Pelt_Deer.p3d";
		weight = 420;
		itemSize[] = {6,3};
		inventorySlot[] = {"DryRackLeather"};
	};
	class CleanedGoatPelt: CleanedPelt_Base
	{
		scope = 2;
		displayName = "A cleaned and prepared Goat Pelt";
		descriptionShort = "A pelt from a goat ready for being tanned into leather or used for other purpose's";
		model = "\dz\gear\consumables\Pelt_Goat.p3d";
		weight = 380;
		itemSize[] = {5,3};
		inventorySlot[] = {"DryRackLeather"};
	};
	class CleanedBearPelt: CleanedPelt_Base
	{
		scope = 2;
		displayName = "A cleaned and prepared Bear Pelt";
		descriptionShort = "A pelt from a bear ready for being tanned into leather or used for other purpose's";
		model = "\dz\gear\consumables\Pelt_Bear.p3d";
		weight = 1200;
		itemSize[] = {8,4};
		inventorySlot[] = {"DryRackLeather"};
	};
	class CleanedWolfPelt: CleanedPelt_Base
	{
		scope = 2;
		displayName = "A cleaned and prepared Wolf Pelt";
		descriptionShort = "A pelt from a wolf ready for being tanned into leather or used for other purpose's";
		model = "\dz\gear\consumables\Pelt_Wolf.p3d";
		weight = 1200;
		itemSize[] = {5,3};
		inventorySlot[] = {"DryRackLeather"};
	};
	class CleanedSheepPelt: CleanedPelt_Base
	{
		scope = 2;
		displayName = "A cleaned and prepared Sheep Pelt";
		descriptionShort = "A pelt from a sheep ready for being tanned into leather or used for other purpose's";
		model = "\dz\gear\consumables\Pelt_Sheep.p3d";
		weight = 1200;
		itemSize[] = {5,3};
		inventorySlot[] = {"DryRackLeather"};
	};
	class CleanedMouflonPelt: CleanedPelt_Base
	{
		scope = 2;
		displayName = "A cleaned and prepared Mouflon Pelt";
		descriptionShort = "A pelt from a mouflon ready for being tanned into leather or used for other purpose's";
		model = "\dz\gear\consumables\Pelt_Mouflon.p3d";
		weight = 1200;
		itemSize[] = {4,3};
		inventorySlot[] = {"DryRackLeather"};
	};
};
