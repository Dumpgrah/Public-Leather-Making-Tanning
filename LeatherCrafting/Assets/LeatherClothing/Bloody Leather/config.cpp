class CfgPatches
{
	class Dirt_Grass_Leather
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Characters_Tops","DZ_Gear_Cultivation"};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class Clothing;
	class LeatherJacket_ColorBase;
	class LeatherPants_ColorBase;
	class LeatherGloves_ColorBase;
	class LeatherHat_ColorBase;
	class LeatherStorageVest_ColorBase;
	class LeatherJacket_Bloody: LeatherJacket_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.85;
		hiddenSelectionsTextures[] = 
		{
			"LeatherCrafting\Assets\LeatherClothing\Bloody Leather\Shirt\Shirt_co.paa",
			"LeatherCrafting\Assets\LeatherClothing\Bloody Leather\Shirt\Shirt_co.paa",
			"LeatherCrafting\Assets\LeatherClothing\Bloody Leather\Shirt\Shirt_co.paa"
		};
		hiddenSelectionsMaterials[] = 
		{
			"LeatherCrafting\Assets\LeatherClothing\Bloody Leather\Shirt\Bloody Shirt.rvmat","LeatherCrafting\Assets\LeatherClothing\Bloody Leather\Shirt\Bloody Shirt.rvmat","LeatherCrafting\Assets\LeatherClothing\Bloody Leather\Shirt\Bloody Shirt.rvmat"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\characters\tops\data\Bloody Shirt.rvmat","DZ\characters\tops\data\Bloody Shirt.rvmat"}},{0.7,{}},{0.5,{"DZ\characters\tops\Data\Bloody Shirt.rvmat","DZ\characters\tops\Data\Bloody Shirt.rvmat"}},{0.3,{}},{0.0,{"DZ\characters\tops\Data\Bloody Shirt.rvmat","DZ\characters\tops\Data\Bloody Shirt.rvmat"}}};
				};
			};
			class GlobalArmor{};
		};
	};
	class LeatherPants_Bloody: LeatherPants_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.85;
		hiddenSelectionsTextures[] = 
		{
			"LeatherCrafting\Assets\LeatherClothing\Bloody Leather\Pants\Pants_co.paa",
			"LeatherCrafting\Assets\LeatherClothing\Bloody Leather\Pants\Pants_co.paa",
			"LeatherCrafting\Assets\LeatherClothing\Bloody Leather\Pants\Pants_co.paa"
		};
		hiddenSelectionsMaterials[] = 
		{
			"LeatherCrafting\Assets\LeatherClothing\Bloody Leather\Pants\Bloody Pants.rvmat","LeatherCrafting\Assets\LeatherClothing\Bloody Leather\Pants\Bloody Pants.rvmat","LeatherCrafting\Assets\LeatherClothing\Bloody Leather\Pants\Bloody Pants.rvmat"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\characters\tops\data\Bloody Shirt.rvmat","DZ\characters\tops\data\Bloody Shirt.rvmat"}},{0.7,{}},{0.5,{"DZ\characters\tops\Data\Bloody Shirt.rvmat","DZ\characters\tops\Data\Bloody Shirt.rvmat"}},{0.3,{}},{0.0,{"DZ\characters\tops\Data\Bloody Shirt.rvmat","DZ\characters\tops\Data\Bloody Shirt.rvmat"}}};
				};
			};
			class GlobalArmor{};
		};
	};
	class LeatherGloves_Bloody: LeatherGloves_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.85;
		hiddenSelectionsTextures[] = 
		{
			"LeatherCrafting\Assets\LeatherClothing\Bloody Leather\Gloves\Gloves_co.paa",
			"LeatherCrafting\Assets\LeatherClothing\Bloody Leather\Gloves\Gloves_co.paa",
			"LeatherCrafting\Assets\LeatherClothing\Bloody Leather\Gloves\Gloves_co.paa"
		};
		hiddenSelectionsMaterials[] = 
		{
			"LeatherCrafting\Assets\LeatherClothing\Bloody Leather\Gloves\Bloody Gloves.rvmat","LeatherCrafting\Assets\LeatherClothing\Bloody Leather\Gloves\Bloody Gloves.rvmat","LeatherCrafting\Assets\LeatherClothing\Bloody Leather\Gloves\Bloody Gloves.rvmat"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\characters\tops\data\Bloody Shirt.rvmat","DZ\characters\tops\data\Bloody Shirt.rvmat"}},{0.7,{}},{0.5,{"DZ\characters\tops\Data\Bloody Shirt.rvmat","DZ\characters\tops\Data\Bloody Shirt.rvmat"}},{0.3,{}},{0.0,{"DZ\characters\tops\Data\Bloody Shirt.rvmat","DZ\characters\tops\Data\Bloody Shirt.rvmat"}}};
				};
			};
			class GlobalArmor{};
		};
	};
	class LeatherVest_Bloody: LeatherStorageVest_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.85;
		hiddenSelectionsTextures[] = 
		{
			"LeatherCrafting\Assets\LeatherClothing\Bloody Leather\Vest\Vest_co.paa",
			"LeatherCrafting\Assets\LeatherClothing\Bloody Leather\Vest\Vest_co.paa",
			"LeatherCrafting\Assets\LeatherClothing\Bloody Leather\Vest\Vest_co.paa"
		};
		hiddenSelectionsMaterials[] = 
		{
			"LeatherCrafting\Assets\LeatherClothing\Bloody Leather\Vest\Bloody Vest.rvmat",
			"LeatherCrafting\Assets\LeatherClothing\Bloody Leather\Vest\Bloody Vest.rvmat",
			"LeatherCrafting\Assets\LeatherClothing\Bloody Leather\Vest\Bloody Vest.rvmat"
};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\characters\tops\data\Bloody Shirt.rvmat","DZ\characters\tops\data\Bloody Shirt.rvmat"}},{0.7,{}},{0.5,{"DZ\characters\tops\Data\Bloody Shirt.rvmat","DZ\characters\tops\Data\Bloody Shirt.rvmat"}},{0.3,{}},{0.0,{"DZ\characters\tops\Data\Bloody Shirt.rvmat","DZ\characters\tops\Data\Bloody Shirt.rvmat"}}};
				};
			};
			class GlobalArmor{};
		};
	};
};
