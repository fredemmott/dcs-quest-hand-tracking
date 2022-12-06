/*
 * MIT License
 *
 * Copyright (c) 2022 Fred Emmott <fred@fredemmott.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

namespace winrt::HTCCSettings::implementation {
MainWindow::MainWindow() {
  InitializeComponent();
  Title(L"HTCC Settings");
}

void MainWindow::Navigate(
  const IInspectable& sender,
  const Microsoft::UI::Xaml::Controls::NavigationViewItemInvokedEventArgs&
    args) noexcept {
  if (args.IsSettingsInvoked()) {
    // TODO
    return;
  }

  auto item = args.InvokedItemContainer()
                .try_as<Microsoft::UI::Xaml::Controls::NavigationViewItem>();

  if (!item) {
    // FIXME: show an error?
    return;
  }

  // TODO: you probably want to use item.Tag() to identify a specific item
  Frame().Navigate(xaml_typename<DemoPage>(), item.Content());
}

}// namespace winrt::HTCCSettings::implementation
