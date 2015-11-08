# Entity API Example
An example custom Blog entity for Drupal 7.

The blog entity has a Title and Body. The author and the created/updated timestamps are automatically generated similar to how nodes are. Author UID is pulled from the current user; both timestamps are pulled from the `PHP` global `REQUEST_TIME`.

## Usage
This is a Features package, install it and enable as you would for any other feature.

### View all blogs, administratively.
Visit [http://example.com/admin/blogs](http://example.com/admin/blogs) to view teh blog listing. Obviously, after a fresh install there will be no blogs.

### Create a blog.
From the admin listing above, click on "add blog", or visit [http://www.example.com/admin/blogs/add](http://www.example.com/admin/blogs/add) direclty. Fill out the fields and click "Save blog".

### View a blog on the frontend.
From the admin listing, click a blog title, or visit the blog directly at [http://example.com/blog/$ID](http://example.com/blog/$ID), where `$ID` is the blog id.

## View a paged list of all blogs on the frontend.
Visit [http://example.com/blogs](http://example.com/blogs) to view a paged listing of blogs. You'll have to create more than 10 blogs to see a pager.
