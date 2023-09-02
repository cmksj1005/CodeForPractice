var mongoose = require('mongoose');
var Schema = mongoose.Schema;

mongoose.connect(
  'mongodb+srv://cmksj1005:TJk0MsDA6iHiUBls@senecaweb.9lyby8c.mongodb.net/?retryWrites=true&w=majority'
);

var companySchema = new Schema({
  companyName: {
    type: String,
    unique: true, // If I make same companyName, it will make an error
  },
  address: String,
  phone: String,
  employeeCount: {
    type: Number,
    default: 0,
  },
  country: String,
});

var Company = mongoose.model('companies', companySchema);

// var dataObjectTest = {
//   companyName: 'The Kwik-E-Mart',
//   address: 'Springfield',
//   phone: '212-842-4923',
//   employeeCount: 3,
//   country: 'U.S.A',
// };

var kwikEMart = new Company({
  companyName: 'The Kwik-E-Mart',
  address: 'Springfield',
  phone: '212-842-4923',
  employeeCount: 3,
  country: 'U.S.A',
});

kwikEMart
  .save()
  .then(() => {
    console.log('success! data added');
  })
  .catch((err) => {
    console.log('err: ' + err);
  });

// Company.findOne({ address: 'Springfield' }, 'address phone') // display address and phone only
//   //Company.find({ address: 'Springfield' })
//   .exec()
//   .then((data) => {
//     if (data) {
//       console.log(data);
//     } else {
//       console.log('no data');
//     }
//   })
//   .catch((err) => {
//     console.log(err);
//   });

// var commentChain = new Comment({
//   comment: 'Star Wars is awesome',
//   author: 'Author 1',
//   date: new Date(),
//   comments: [
//     {
//       comment: 'I agree',
//       author: 'Author 2',
//       date: new Date(),
//       comments: [
//         {
//           comment: 'I agree with Author 2',
//           author: 'Author 3',
//           date: new Date(),
//           comments: [],
//         },
//       ],
//     },
//   ],
// });

// Company.updateOne(
//   { address: 'Springfield' },
//   { $set: { companyName: 'Some generic name' } }
// )
//   .exec()
//   .then((data) => {
//     console.log(data);
//   });

Company.deleteOne({ address: 'Springfield' })
  .exec()
  .then((data) => {
    console.log(data);
  });
