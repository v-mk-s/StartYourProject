#include "application_core.h"


ApplicationCore::ApplicationCore()
{
    _context = std::make_shared<Context>();
    login_ui = new LoginPage(_context);

}
