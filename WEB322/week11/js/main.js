$(document).ready(function () {
  console.log('document ready!');
  $('.title').css('color', 'red');
  //   $('ul.list1 li').each(function (index) {
  //     $(this).append(' ' + index);
  //   });
  // $('ul.list1 li').filter(':odd').css('font-weight', 'bold');

  $('ul.list1').on('click', 'li', function () {
    $(this).css('color', 'red');
  });

  $('ul.list1').append('<li>I get the event too!</li>');
});

console.log('file loaded');
