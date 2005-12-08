// rTorrent - BitTorrent client
// Copyright (C) 2005, Jari Sundell
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
// In addition, as a special exception, the copyright holders give
// permission to link the code of portions of this program with the
// OpenSSL library under certain conditions as described in each
// individual source file, and distribute linked combinations
// including the two.
//
// You must obey the GNU General Public License in all respects for
// all of the code used other than OpenSSL.  If you modify file(s)
// with this exception, you may extend this exception to your version
// of the file(s), but you are not obligated to do so.  If you do not
// wish to do so, delete this exception statement from your version.
// If you delete this exception statement from all source files in the
// program, then also delete it here.
//
// Contact:  Jari Sundell <jaris@ifi.uio.no>
//
//           Skomakerveien 33
//           3185 Skoppum, NORWAY

#ifndef RTORRENT_CONTROL_H
#define RTORRENT_CONTROL_H

#include <torrent/torrent.h>

#include "globals.h"

namespace ui {
  class Root;
}

namespace core {
  class Manager;
}

namespace display {
  class Manager;
}

namespace input {
  class InputEvent;
  class Manager;
}  

class Control {
public:
  Control();
  ~Control();
  
  bool                is_shutdown_completed()       { return m_shutdownReceived && torrent::is_inactive(); }
  bool                is_shutdown_received()        { return m_shutdownReceived; }

  ui::Root*           ui()                          { return m_ui; }
  core::Manager*      core()                        { return m_core; }
  display::Manager*   display()                     { return m_display; }
  input::Manager*     input()                       { return m_input; }
  input::InputEvent*  input_stdin()                 { return m_inputStdin; }

  void                initialize();
  void                cleanup();

  void                receive_shutdown();

private:
  Control(const Control&);
  void operator = (const Control&);

  bool                m_shutdownReceived;

  ui::Root*           m_ui;
  core::Manager*      m_core;
  display::Manager*   m_display;
  input::Manager*     m_input;
  input::InputEvent*  m_inputStdin;

  rak::priority_item  m_taskShutdown;
};

#endif
