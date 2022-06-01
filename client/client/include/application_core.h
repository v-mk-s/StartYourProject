#ifndef APPLICATIONCORE_H
#define APPLICATIONCORE_H

#include "login_page.h"
#include "register_page.h"
#include "project_page.h"
#include "publish_post_page.h"
#include "user_edit_page.h"
#include "user_page.h"
#include "utils.hpp"
#include "general.h"
#include <QWidget>

#include <memory>


class ApplicationCore
{
public:
    ApplicationCore();

    LoginPage* getLoginPage() { return login_ui; }

private:
      LoginPage* login_ui;
      std::shared_ptr<Context> _context;


//    RegisterPage* register_ui;
//    ProjectPage* project_ui;
//    PublishPostPage* publish_post_ui;
//    UserEditPage* user_edit_ui;
//    UserPage* user_ui;

};

#endif // APPLICATIONCORE_H
