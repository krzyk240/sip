#include "simlib/debug.hh"
#include "src/sip_error.hh"
#include "src/sip_package.hh"

namespace commands {

void name(ArgvParser args) {
    STACK_UNWINDING_MARK;

    SipPackage sp;
    if (args.size() > 0) {
        sp.replace_variable_in_simfile("name", args.extract_next().operator StringView());
    }

    try {
        sp.simfile.load_name();
        stdlog("name = ", sp.simfile.name.value());
    } catch (const std::exception& e) {
        log_warning(e.what());
    }
}

} // namespace commands
