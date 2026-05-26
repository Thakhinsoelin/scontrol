#include "Cmd.h"
#include "Commands.h"

#include <print>
#include <string>

void showHelp() {
	std::print(R"(Usage: scontrol <command> [options]

Commands:
    commit              Commit Current Changes
    status              Show current Status
    init                Initialize the version control
    help                Show this message
    checkout [commit]   Checkout that commit
)");
}

void CmdHandler::parseAndDispatch(int argc, char** argv)
{
	if (argc == 1) {
		showHelp();
		exit(1);
	}

	for (int i = 1; i <= argc; i++)
	{
		if (std::string(argv[i]) == "help") {
			showHelp();
			if (i != argc - 1) {
				std::print("Unknown Options: help {}", argv[i]);
				break;
			}
			break;
		}
		if (std::string(argv[i]) == "init")
		{
			handleInit();
			if (i != argc - 1) {
				std::print("Unknown Options: init {}", argv[i]);
				break;
			}
			break;
		}
		else {
			std::print("Unknown Options\n");
			break;
		}
	}
}
