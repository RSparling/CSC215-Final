#pragma once
namespace States {
	/*
	<summary>
	A virutal state to allow for polymorphism.
	</summary>
	*/
	class State
	{
	public:
		virtual bool CanEnter() = 0; //checks if the state can be entered, should only be false on an error.
		virtual void Enter() = 0; //called when the state is entered, used for setup and first run operations
		virtual bool Execute() = 0; //called every frame, used for the main logic of the state. Returns false on error or when the state is finished.
		virtual State* Exit() = 0; //called when the state is exited, used for cleanup and last run operations
	};
}